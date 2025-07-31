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
const int N = 1e6+5;
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

vector<pair<int, int>> g[N];
int team[N], vis[N], mark[N];
int n, m, k;
vector<array<int, 3>> edges;
int cnt = 0;
void bfs(int u) {

	for(int i = 1; i <= n; i++) mark[i] = M;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	mark[1] = 0;
	pq.push({0, u});
	
	while(pq.size()) {
		auto [id, u] = pq.top(); pq.pop();
		if(id + 1 > k) continue;
		if(id != mark[u]) continue;
		for(auto [v, w] : g[u]) {
			if(mark[u] + w < mark[v]){
				mark[v] = mark[u] + w;
				pq.push({mark[v], v});
			}
		}

	}

}
void solve(int id){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
		edges.pb({u, v, w});
	}

	bfs(1);
	if(mark[n] < k) return cout << "No\n", void();
	cout << "Yes\n";

	for(int i = 0; i < m; i++) {
		auto [u, v, w] = edges[i];
		if(w == 0) continue;
		int ans = min(k, max(mark[u], mark[v]));
		cout << ans << nl;
		
	}
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