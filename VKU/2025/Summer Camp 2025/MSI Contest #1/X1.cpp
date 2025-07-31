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
const int N = 2500;
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

char c[N][N];
int m, n, k;
int x_s, y_s, x_t, y_t;
int f[N][N];
bool check(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void solve(int id){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> c[i][j];
			f[i][j] = M;
		}
	}
	cin >> x_s >> y_s >> x_t >> y_t;
	queue<pair<int, int>> q;
	q.push({x_s, y_s});
	f[x_s][y_s] = 0;
	while(q.size()) {
		auto [x, y] = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			for(int p = 1; p <= k; p++) {
				int dx = x + moveX[i] * p;
				int dy = y + moveY[i] * p;
				if(!check(dx, dy) || c[dx][dy] == '#' || f[dx][dy] < f[x][y] + 1) break;
				if(f[dx][dy] == f[x][y] + 1) continue;
				f[dx][dy] = f[x][y] + 1;
				q.push({dx, dy});
			}
		}
	}
	// for(int i = 1; i <= n; i++) {
	// 	for(int j = 1; j <= m; j++) {
	// 		cout << f[i][j] << ' ';
	// 	}
	// 	cout << nl;
	// }
	cout << (f[x_t][y_t] == M ? -1 : f[x_t][y_t]);
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