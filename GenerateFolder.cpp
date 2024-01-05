#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

int main() {
    std::string folderName;
    
    // Get the folder name from the user
    std::cout << "Enter folder name: ";
    folderName = "Atcoder ABC 334";
    // std::cin >> folderName;

    // Check if the folder already exists
    struct stat info;
    if (stat(folderName.c_str(), &info) == 0 && S_ISDIR(info.st_mode)) {
        std::cout << "Folder already exists." << std::endl;
        return 1;
    }

    // Create the folder
    if (mkdir(folderName.c_str()) == 0) {
        std::cout << "Folder created successfully." << std::endl;

        // Create input.txt and output.txt files within the folder
        std::ofstream inputFile(folderName + "/input.inp");
        std::ofstream outputFile(folderName + "/input.out");

        if (inputFile.is_open() && outputFile.is_open()) {
            inputFile.close();
            outputFile.close();
            std::cout << "input.txt and output.txt created successfully." << std::endl;
        } else {
            std::cerr << "Error creating input.txt and output.txt." << std::endl;
            return 1;
        }
    } else {
        std::cerr << "Error creating folder." << std::endl;
        return 1;
    }

    return 0;
}
