// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 4e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}


int l[N], r[N], ans[N];
pair<int, int> query[N];
struct DSU {
	int n;
	vector<int> par;
	vector<vector<int>> g;

	void init(int _n) {
		n = _n;
		par.assign(n + 5, 0);
		g.resize(n + 5);

		for(int i = 1; i <= n; i++) make(i);
	}

	void make(int u, int val = 0) {
		par[u] = u;
		g[u].pb(u);
	}

	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}


	bool unite(int u, int v, int time) {
		u = find(u);
		v = find(v);
		if(u == v) return false;
		if(g[u].size() < g[v].size()) swap(u, v);
		if(u == find(1)) for(auto x : g[v]) ans[x] = time;
		else if(v == find(1)) for(auto x : g[u]) ans[x] = time;
		for(auto x : g[v]) g[u].pb(x); 
		par[v] = u;
		return true;
	}

} dsu;
void solve(int id){
	int n, m;
	cin >> n >> m;
	dsu.init(n);
	for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
	for(int i = 1; i <= m; i++) {
		int p, h;
		cin >> p >> h;
		if(h == 1) query[i] = {p, l[p]}, l[p] = -1;
		else query[i] = {p, r[p]}, r[p] = -1;
	}

	for(int i = 1; i <= n; i++) {
		if(l[i] != -1) dsu.unite(i, l[i], -1);
		if(r[i] != -1) dsu.unite(i, r[i], -1);
	}

	for(int i = m; i >= 1; i--) {
		dsu.unite(query[i].first, query[i].second, i - 1);
	}
	ans[1] = -1;
	for(int i = 1; i <= n; i++) cout << ans[i] << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}