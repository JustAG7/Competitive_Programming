#include<bits/stdc++.h>
using namespace std;


void solve(){
	long long n;
	int ans = 0;
	cin >> n;
	if(0 < n && n < 999999999){
		while(n > 0){
			int number = n % 10;
			if(number % 2 != 0) ans++;
			n /= 10;
		}
		cout << ans;
	}
	else cout << "N";
}
int main(){
	solve();
}