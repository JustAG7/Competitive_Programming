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
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll dp[N][3];
vector<int> g[N];
void dfs(int u,int pre){

	dp[u][1] = dp[u][2] = 1;
	for(auto v : g[u]){
		if(v == pre) continue;
		dfs(v, u);
		dp[u][1] = (dp[u][1] * dp[v][2]) % M;
		dp[u][2] = (dp[u][2] * ((dp[v][1] + dp[v][2]) % M)) % M;
	}
}
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n - 1;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 1);
	cout << (dp[1][1] + dp[1][2]) % M;
	// dbg(dp[1][1]);dbg(dp[1][2]);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}