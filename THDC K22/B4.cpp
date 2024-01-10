#include<bits/stdc++.h>
using namespace std;


void solve(){
	int n;
	cin >> n;
	if(-100 < n && n < 100){
		if(n < 0) cout << abs(n);
		else cout << n * n;
	}	
	else cout << 'N';
}
int main(){
	solve();
}