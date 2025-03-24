#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <chrono>

#pragma comment(lib, "ws2_32.lib")

#define ICMP_ECHO 8
#define ICMP_ECHOREPLY 0
#define ICMP_HEADER_SIZE 8

// ICMP Header structure
struct ICMPHeader {
    unsigned char type;
    unsigned char code;
    unsigned short checksum;
    unsigned short id;
    unsigned short sequence;
};

// Function to calculate the checksum for the ICMP packet
unsigned short checksum(void* buffer, int size) {
    unsigned short* buf = reinterpret_cast<unsigned short*>(buffer);
    unsigned int sum = 0;
    while (size > 1) {
        sum += *buf++;
        size -= 2;
    }
    if (size == 1) {
        sum += *reinterpret_cast<unsigned char*>(buf);
    }
    sum = (sum >> 16) + (sum & 0xffff);
    sum += (sum >> 16);
    return static_cast<unsigned short>(~sum);
}

int main() {
    WSADATA wsaData;
    SOCKET rawSocket;
    struct sockaddr_in destAddr;
    char icmpRequest[32];   // Buffer for ICMP Request
    char recvBuffer[1024];  // Buffer for ICMP Reply
    int result;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock." << std::endl;
        return 1;
    }

    // Create a raw socket for ICMP
    rawSocket = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (rawSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create raw socket. Error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // Set the destination address
    destAddr.sin_family = AF_INET;
    destAddr.sin_addr.s_addr = inet_addr("8.8.8.8");  // Ping Google's public DNS

    // Build the ICMP echo request
    ICMPHeader* icmpHeader = reinterpret_cast<ICMPHeader*>(icmpRequest);
    icmpHeader->type = ICMP_ECHO;
    icmpHeader->code = 0;
    icmpHeader->id = (unsigned short)GetCurrentProcessId();
    icmpHeader->sequence = 1;
    icmpHeader->checksum = 0;

    // Fill in some data for the packet
    char* data = icmpRequest + ICMP_HEADER_SIZE;
    memset(data, 'E', sizeof(icmpRequest) - ICMP_HEADER_SIZE);

    // Calculate the checksum
    icmpHeader->checksum = checksum(icmpRequest, sizeof(icmpRequest));

    // Print ICMP request details
    std::cout << "Sending ICMP Echo Request to 8.8.8.8:" << std::endl;
    std::cout << "Type: " << (int)icmpHeader->type << ", Code: " << (int)icmpHeader->code 
              << ", ID: " << icmpHeader->id << ", Sequence: " << icmpHeader->sequence 
              << ", Checksum: " << icmpHeader->checksum << std::endl;

    // Send the ICMP echo request
    auto startTime = std::chrono::high_resolution_clock::now();
    result = sendto(rawSocket, icmpRequest, sizeof(icmpRequest), 0, (struct sockaddr*)&destAddr, sizeof(destAddr));
    if (result == SOCKET_ERROR) {
        std::cerr << "Failed to send ICMP request. Error: " << WSAGetLastError() << std::endl;
        closesocket(rawSocket);
        WSACleanup();
        return 1;
    }

    // Receive the ICMP echo reply
    struct sockaddr_in replyAddr;
    int replyAddrSize = sizeof(replyAddr);
    result = recvfrom(rawSocket, recvBuffer, sizeof(recvBuffer), 0, (struct sockaddr*)&replyAddr, &replyAddrSize);
    if (result == SOCKET_ERROR) {
        std::cerr << "Failed to receive ICMP reply. Error: " << WSAGetLastError() << std::endl;
        closesocket(rawSocket);
        WSACleanup();
        return 1;
    }

    // Calculate and display the round-trip time
    auto endTime = std::chrono::high_resolution_clock::now();
    auto roundTripTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

    // Parse and print ICMP reply details
    ICMPHeader* replyIcmpHeader = reinterpret_cast<ICMPHeader*>(recvBuffer + 20); // skip IP header (20 bytes)
    std::cout << "\nReceived ICMP Echo Reply from " << inet_ntoa(replyAddr.sin_addr) << ":" << std::endl;
    std::cout << "Type: " << (int)replyIcmpHeader->type << ", Code: " << (int)replyIcmpHeader->code 
              << ", ID: " << replyIcmpHeader->id << ", Sequence: " << replyIcmpHeader->sequence 
              << ", Checksum: " << replyIcmpHeader->checksum << std::endl;

    std::cout << "Round-trip time: " << roundTripTime << " ms" << std::endl;

    // Clean up
    closesocket(rawSocket);
    WSACleanup();
    return 0;
}