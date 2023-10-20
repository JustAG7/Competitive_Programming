#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
const int N = 3e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
db dp[N][N];
db a[N];
void solve(){
	int n;
	cin >> n;
	dp[0][0] = 1.0;
	// dp[i][j] = probabilities when throw i coins and get j tails
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j] = a[i] * (dp[i - 1][j - 1]) + (1.0 - a[i]) * (dp[i - 1][j]);
		}
	}
	db ans = 0;
	for(int i=n/2+1;i<=n;i++) ans += dp[n][i];
	cout << fixed << setprecision(10) << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}