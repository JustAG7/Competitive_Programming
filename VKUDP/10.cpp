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
	int n;
	cin >> n;
	vector<vector<int>> dp(n+5,vector<int> (3,0));
	cin >> dp[0][0] >> dp[0][1] >> dp[0][2];
	for(int i=1;i<n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		dp[i][0]=a+max(dp[i-1][1],dp[i-1][2]);
		dp[i][1]=b+max(dp[i-1][0],dp[i-1][2]);
		dp[i][2]=c+max(dp[i-1][1],dp[i-1][0]);
	}
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}