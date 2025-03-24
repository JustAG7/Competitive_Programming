#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll dp[N][110];
int a[N];
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++) cin >> a[i];
	if(a[0]) dp[0][a[0]] = 1;
	else fill(dp[0],dp[0] + 105,1);
	for(int i=1;i<n;i++){
		if(a[i]){
			dp[i][a[i]] += dp[i-1][a[i]];
			dp[i][a[i]] += (a[i] - 1 > 0)*(dp[i - 1][a[i] - 1]);
			dp[i][a[i]] += (a[i] + 1 <=m)*(dp[i - 1][a[i] + 1]);
			dp[i][a[i]] %= M;
		}
		else{
			for(int j=1;j<=m;j++){
				dp[i][j] += dp[i-1][j];
				dp[i][j] += (j - 1 > 0)*(dp[i - 1][j - 1]);
				dp[i][j] += (j + 1 <=m)*(dp[i - 1][j + 1]);
				dp[i][j] %= M;
			}
		}
	}
	ll ans = 0;
	for(int i=1;i<=m;i++){
		(ans += dp[n-1][i]) %= M;
	}
	cout << ans;

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}