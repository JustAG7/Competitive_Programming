#include<bits/stdc++.h>
using namespace std;

void solve(){
	char c;cin >> c;
	if('a' <= c && c <= 'z') cout << 'L';
	else if('A' <= c && c <= 'Z') cout << 'U';
	else if('0' <= c && c <= '9') cout << 'D';
	else cout << 'O';
}
int main(){
	solve();
}