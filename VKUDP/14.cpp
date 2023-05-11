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
	string a,b;
	cin >> a >> b;
	int n=a.size(),m=b.size();
	vector<vector<int>> dp(n+5,vector<int> (m+5,1e9));
	dp[0][0]=0;
	//Toi quen de bai la tim min de xau a == xau b
	for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				if(i==0) dp[i][j]=j;
				else if(j==0) dp[i][j]=i;
				else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
			}
		}
		cout << dp[n][m];
	}
	int main(){
		fast;
		indef();
		int tt=1;
		while(tt--) solve();
}