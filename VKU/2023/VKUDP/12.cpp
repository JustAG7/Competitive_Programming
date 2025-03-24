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
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
void solve(){
	int n,m;
	cin >> n  >> m;
	vector<vector<ll>> dp(n+5,vector<ll> (m+5,0));

	dp[0][1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			if (x == '.') dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
		}
	cout << dp[n][m];
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}