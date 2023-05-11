#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van
void solve(){
	int n;
	cin >> n;
	cout << n/2 << nl;
	for(int i=1;i<=n/2-1;i++) cout << 2 << ' ';
	if(n & 1) cout << 3;
	else cout << 2;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}