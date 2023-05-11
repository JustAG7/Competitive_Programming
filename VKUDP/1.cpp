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
	int n=1000005;
	ll ans=1;
	vector<ll> dp(n+5,0);
	vector<ll> rs(n+5,0);
	dp[1]=1;
	rs[1]=1;
	for(int i=2;i<=n;i++){
		if(i & 1) dp[i]=dp[(i-1)/2]+dp[(i-1)/2+1];
		else dp[i]=dp[i/2];
		ans=max(ans,dp[i]);
		rs[i]=ans;
	}
	int t;
	cin >> t;
	while(t--){
		int x;
		cin >> x;
		cout << rs[x] << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}