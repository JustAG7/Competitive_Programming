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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll dp[N][105];
ll last[30], previous[N];
void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i=0;i<n;i++){
		previous[i + 1] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i + 1;
	}
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		dp[i][0] = 1;
		for(int j=1;j<=min(i, k);j++){
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % M;
			if(previous[i]){
				ll remove = j - (i - previous[i]);
				if(0 <= remove && remove <= k){
					dp[i][j] = (dp[i][j] - dp[previous[i] - 1][remove] + M) % M;
				}
			}
		}
	}

	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=k;j++){
	// 		cerr << dp[i][j] << ' ';
	// 	}
	// 	cerr << nl;
	// }
	cout << dp[n][k];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}