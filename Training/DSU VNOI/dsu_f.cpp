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

struct DSU {
	int n;
	vector<int> par, sz;

	void init(int _n) {
		n = _n;
		par.assign(n + 5, 0);
		sz.assign(n + 5, 0);
	}

	void make(int u, int val = 0) {
		par[u] = u;
		sz[u] = 1;
	}

	int find(int u) {
		return u == par[u] ? u : par[u] = find(par[u]);
	}

	bool unite(int u, int v) {
		u = find(u);
		v = find(v);
		if(u == v) return false;
		par[v] = u;
		return true;
	}
} dsu;

void solve(int id){
	int n, m;
	cin >> n >> m;
	dsu.init(n);
	for(int i = 1; i <= n; i++) dsu.make(i);
	while(m--) {
		char t; int x;
		cin >> t >> x;
		if(t == '?') cout << (dsu.find(x) == 0 ? -1 : dsu.find(x)) << nl;
		else dsu.unite(dsu.find(x + 1), dsu.find(x));
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