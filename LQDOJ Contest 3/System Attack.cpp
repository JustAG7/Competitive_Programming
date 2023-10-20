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
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vi g[N];
int f[N];
int vis[N];
int n,m;

int dfs(int u){
	if(vis[u]) return 0;
	if(f[u] != -1) return f[u];
	vis[u] = 1;
	f[u] = 1;
	for(auto v : g[u]){
		if(!vis[v]) f[u] += dfs(v);
	}
	return f[u];
}
void solve(){
	cin >> n >> m;
	memset(f,-1,sizeof(f));
	int ans = 0;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
	}
	vi res;
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		ans = max(ans, dfs(i));
	}
	for(int i=1;i<=n;i++){
		if(ans == dfs(i)) res.pb(i);
	}
	// for(int i=1;i<=n;i++) cout << f[i] << ' ';
	cout << ans << ' ' << res.size() << nl;
	for(auto x : res) cout << x << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}