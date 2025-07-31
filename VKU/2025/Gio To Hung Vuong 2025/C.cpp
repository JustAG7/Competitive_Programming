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
const int N = 5e3+5;
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

int n, m, k;
int s, t;
vector<pair<int,int>> g[N];
ll dist[N][N];

ll ans = inf;

void pfs() {
	priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;
	pq.push({0, 0, s});
	while(pq.size()) {
		auto [cost, ticket, u] = pq.top();pq.pop();

		if(u == t) continue;

		for(auto [v, w] : g[u]) {
			if (cost + w < dist[v][ticket]) {
				dist[v][ticket] = cost + w;
				pq.push({dist[v][ticket], ticket, v});
			}

			if(ticket < k) {
				ll new_cost = cost + w / 2;
				if(new_cost < dist[v][ticket + 1]) {
					dist[v][ticket + 1] = new_cost;
					pq.push({dist[v][ticket + 1], ticket + 1, v});
				}
			}
		}
	}
}
void solve(int id){
	cin >> n >> m >> k;
	cin >> s >> t;
	
	memset(dist, 0x3f, sizeof dist);

	dist[s][0] = 0;
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	pfs();
	for(int i = 0; i <= k; i++) ans = min(ans, dist[t][i]);
	cout << ans << nl;
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