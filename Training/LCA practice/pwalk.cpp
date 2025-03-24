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
const int N = 1e3+5;
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
int dist[N];
int up[N][10];
int h[N];
void dfs(int u){
	for(auto [v, w] : g[u]){
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;

		dist[v] = dist[u] + w;
		up[v][0] = u;
		for(int i=1;i<10;i++){
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
				u = up[u][i];
			}
		}
	}
	if(u == v) return u;

	int k = __lg(h[u]);
	for(int i=k;i>=0;i--){
		if(up[v][i] != up[u][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
void solve(){
	int n,q;
	cin >> n >> q;
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs(1);
	while(q--){
		int a,b;
		cin >> a >> b;
		int LCA = lca(a, b);
		cout << dist[a] + dist[b] - 2*dist[LCA] << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}