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
	int n,k;
	cin >> n >> k;
	vector<ll> a(n+5,0);
	vector<ll> dp(n+5,0);
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[2]=abs(a[2]-a[1]);
	for(int i=3;i<=n+1;i++){
		if(i>k) dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),min(dp[i-2]+abs(a[i]-a[i-2]),dp[i-k]+abs(a[i]-a[i-k])));
		else dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
	}
	for(int i=1;i<=n;i++) cout << dp[i] << ' ';
	cout << dp[n];
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}