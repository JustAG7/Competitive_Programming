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

template<class T>
	struct Compressor{
		vector<T> res;

		int getsz() {
			return res.size();
		}

		void add(T x) {
			res.pb(x);
		}

		void compress() {
			sort(all(res));
			res.erase(unique(all(res)), res.end());
		}

		T find(T x) {
			return lower_bound(all(res), x) - res.begin() + 1;
		}
	};


struct SegTree {
	vector<pair<int, int>> t;
	int n;

	void init(int _n) {
		n = _n;
		t.assign(4 * n + 5, {0, 0});
	}

	void update(int id, int l, int r, int idx, pair<int, int> val) {
		if(idx < l || r < idx) return;
		if(l == r) {
			t[id] = max(t[id], val);
			return;
		}
		int m = (l + r) / 2;
		update(id * 2, l, m, idx, val);
		update(id * 2 + 1, m + 1, r, idx, val);
		t[id] = max(t[id * 2], t[id * 2 + 1]);
	}

	pair<int, int> get(int id, int l, int r, int u, int v) {
		if(r < u || v < l) return {0, 0};
		if(u <= l && r <= v) return t[id];
		int m = (l + r) / 2;
		return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	}

	void update(int idx, pair<int, int> val) {
		update(1, 1, n, idx, val);
	}

	pair<int, int> get(int l, int r) {
		return get(1, 1, n, l, r);
	}
} inc, dcr;

int trace[N][2];
int a[N], f[N];
void getPath(int u, int flag) {
	if(u == 0) return;
	getPath(trace[u][flag], !flag);
	cout << a[u] << ' ';
}
void solve(int id){
	int n;
	cin >> n;
	Compressor<int> cp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cp.add(a[i]);
	}

	cp.compress();
	int m = cp.getsz();
	inc.init(m); dcr.init(m);
	for(int i = 1; i <= n; i++) {
		int pos = cp.find(a[i]);
		
		auto [p1, par1] = inc.get(pos + 1, m);
		trace[i][0] = par1;
		dcr.update(pos, {p1 + 1, i});

		auto [p2, par2] = dcr.get(1, pos - 1);
		trace[i][1] = par2;
		inc.update(pos, {p2 + 1, i});
	}

	auto [ans1, par1] = inc.get(1, m);
	auto [ans2, par2] = dcr.get(1, m);

	cout << max(ans1, ans2) << nl;
	if(ans1 > ans2) getPath(par1, 1);
	else getPath(par2, 0);
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