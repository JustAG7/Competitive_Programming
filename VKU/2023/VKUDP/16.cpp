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
	vector<vector<int>> dp(n+5, vector<int> (m+5,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	string ans;
	for(int i=n,j=m;i>0 && j>0;){
		if(a[i-1]==b[j-1]){
			ans+=a[i-1];
			i--;j--;
		}
		else{
			if(dp[i-1][j]>dp[i][j-1]) i--;
			else j--;
		}
	}
	reverse(all(ans));
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}