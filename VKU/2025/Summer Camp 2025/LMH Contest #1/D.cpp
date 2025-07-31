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
const int N = 1e3+5;
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

int vis[N][N];
int a[N][N];
int n, m;
pair<int, int> par[N][N];
priority_queue<array<int, 3>> pq;
bool check(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

pair<int, int> find(pair<int, int> u) {
	return u == par[u.first][u.second] ? u : par[u.first][u.second] = find(par[u.first][u.second]);
}

bool unite(pair<int, int> u, pair<int, int> v) {
	u = find(u);
	v = find(v);
	if(u == v) return false;
	par[v.first][v.second] = u;
	return true;
}
void solve(int id){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			par[i][j] = {i, j};
			pq.push({a[i][j], i, j});
		}
	}

	int maxH = pq.top()[0], ans = 0, cur = 0;
	set<pair<int, int>> s;
	for(int bound = maxH; bound >= 0; bound--) {
		while(pq.size() && pq.top()[0] > bound) {
			auto [v, x, y] = pq.top(); pq.pop();
			vis[x][y] = 1;
			vector<pair<int, int>> p;
			for(int i = 0; i < 4; i++) {
				int dx = x + moveX[i];
				int dy = y + moveY[i];

				if(check(dx, dy) && vis[dx][dy]) {
					p.pb({dx, dy});
				}

			}
			if(!p.size()) cur++;
			else {
				unite(p[0], make_pair(x, y));
				for(int i = 1; i < p.size(); i++) {
					if(unite(p[i], make_pair(x, y))) cur--;
				}
			}
		}
		ans = max(ans, cur);
	}	
	cout << ans;
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