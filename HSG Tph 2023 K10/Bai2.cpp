#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long

void indef(){
	// tao 2 file input.inp lam file input
	// input.out lam file output
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(){
	string s;
	cin >> s;
	transform(s.begin(),s.end(),s.begin(), ::tolower);
	cout << (s == "yes" ? "YES\n" : "NO\n");
}
int main(){
	fast;
	indef(); // xoa cai nay neu khong muon dung file
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}