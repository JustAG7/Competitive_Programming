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
           

const int M = 1e9+7;
const int N = 5e2+5;
const ll inf = 2e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

// void indef(){
// 	#define JA "WF"
// 	if(fopen(JA ".inp", "r")){
// 		freopen(JA ".inp","r",stdin);
// 		freopen(JA ".out","w",stdout);	
// 	}
// }

ll dist[N][N];
int n, m, airport = 0;
void update(int u) {
	for(int x = 0; x <= n; x++) {
		for(int y = 0; y <= n; y++) {
			dist[x][y] = min(dist[x][y], dist[x][u] + dist[u][y]);
		}
	}
}
void solve(){
	
	cin >> n >> m;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			if(i == j) continue;
			dist[i][j] = inf;
		}
	}
	
	for(int i = 0; i < m; i++) {
		ll u, v, w; cin >> u >> v >> w;
		dist[u][v] = min(dist[u][v], w);
		dist[v][u] = dist[u][v];
	}
	ll k, t;
	cin >> k >> t;
	for(int i = 0; i < k; i++) {
		int u; cin >> u;
		dist[u][airport] = t;
		dist[airport][u] = 0;
	}

	for(int i = 0; i <= n; i++) update(i);

	int q; cin >> q;
	while(q--) {
		int query; cin >> query;
		if(query == 1) {
			ll u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = min(dist[u][v], w);
			dist[v][u] = dist[u][v];

			update(u);
			update(v);
		}
		else if(query == 2) {
			int u;
			cin >> u;
			dist[u][airport] = t;
			dist[airport][u] = 0;

			update(airport);
			update(u);
		}
		else {
			ll ans = 0;
			for(int u = 1; u <= n; u++) {
				for(int v = 1; v <= n; v++) {
					ll res = dist[u][v];
					if(res >= inf) continue;
					// cout << u << ' ' << v << ' ' << res << nl;
					ans += res;
				}
			}
			cout << ans << nl;
		}
	}

}
int main(){
	fast;
	// indef();
	int tt=1;
	solve();
}