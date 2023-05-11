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
	vector<int> a(n+5),dp(k+5,0);
	for(int i=0;i<n;i++) cin >> a[i];
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			if(a[i]<=j){
				dp[j]=(dp[j]+dp[j-a[i]])%M;
			}
		}
	}
	//for(int i=0;i<=k;i++) cout << dp[i] << ' ';
	//cout << nl;
	cout << dp[k]%M;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}