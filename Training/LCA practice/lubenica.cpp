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
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
vector<pair<int,int>> g[N];
pair<int,int> f[N];
int h[N];
int up[N][17];
int par[N];
int rootMin = M, rootMax = 0;
int maxX = 0, minX = M;
void dfs(int u){
	for(auto [v, w] : g[u]){
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;
		par[v] = u;
		f[v].X = f[v].Y = w;
		up[v][0] = u;
		for(int i=1;i<17;i++){
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		dfs(v);
	}
}
int lca(int u,int v){
	if(h[u] != h[v]){
		if(h[u] < h[v]) swap(u, v);
		int k = h[u] - h[v];
		for(int i=0;(1 << i) <= k;i++){
			if(k >> i & 1){
				if(par[u] != v){
					maxX = max({maxX, f[par[u]]});
					minX = min({minX, f[par[u]]});
				}
				maxX = max({maxX, f[u]});
				minX = min({minX, f[u]});
				u = up[u][i];
			}
		}
	}

	if(u == v) return u;
	maxX = max({maxX, f[u], f[v]});
	minX = min({minX, f[u], f[v]});
	int k = __lg(h[u]);
	for(int i=k;i>=0;i--){
		if(up[u][i] != up[v][i]){
			maxX = max({maxX, f[u], f[v]});
			minX = min({minX, f[u], f[v]});
			if(par[u] != v){
				maxX = max({maxX, f[par[u]]});
				minX = min({minX, f[par[u]]});
			}
			u = up[u][i];
			v = up[v][i];
		}
	}
	maxX = max({maxX, f[u], f[v]});
	minX = min({minX, f[u], f[v]});
	return up[u][0];
}
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	dfs(1);
	int q;
	cin >> q;
	while(q--){
		int a,b;
		cin >> a >> b;
		maxX = 0, minX = M;
		int LCA = lca(a, b);
		cout << minX << ' ' << maxX << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
