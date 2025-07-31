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
const int N = 3e5+5;
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

vector<int> g[N];
int vis[N], vis2[N];
bool ok = true, ok2 = true;
vector<int> topo, ans;
int it = 1;
void dfs(int u) {
	vis[u] = 1;
	for(auto v : g[u]) {
		if(vis[v] == 1) {
			cout << -1;
			exit(0);
		}
		if(!vis[v]) dfs(v);
	}
	topo.pb(u);
	vis[u] = 2;
}

void dfs2(int u, int next) {
	// cout << u << ' ' << next << nl;
	vis2[u] = 1;
	for(auto v : g[u]) {
		if(v != next) continue;
		dfs2(v, topo[++it]); 
	}
}
void solve(int id){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) dfs(i);
	}
	reverse(all(topo));
	dfs2(topo[0], topo[it]);
	for(int i = 1; i <= n; i++) if(!vis2[i]) return cout << -1, void();
	cout << n - 1 << nl;
	for(auto x : topo) cout << x << ' ';

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