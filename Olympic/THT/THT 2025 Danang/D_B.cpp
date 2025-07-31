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

int a[N];
struct Segtree{
	int size;
	vector<ll> st, lazySet;
	void init(int n){
		size = n;
		st.assign(4 * n + 5, 0LL);
		lazySet.assign(4 * n + 5, -1);
		build(1, 1, size);
	}

	void build(int id, int l, int r) {
		if(l == r) {
			st[id] = a[l];
			return;
		}
		int m = (l + r) / 2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		pullUp(id);
	}

	void pushDown(int id,int l,int r){
		int m = (l + r)/2;
		if(lazySet[id] != -1){

			lazySet[id * 2 + 1] = lazySet[id];
			lazySet[id * 2] = lazySet[id];

			st[id * 2] = lazySet[id] * 1LL * (m - l + 1);
			st[id * 2 + 1] = lazySet[id] * 1LL * (r - m);

			lazySet[id] = -1;
		}
	}

	void pullUp(int id){
		st[id] = st[id * 2] + st[id * 2 + 1];
	}
	void set(int id,int l,int r,int u,int v,int x){
		if(v < l || r < u) return;
		if(u <= l && r <= v){
			st[id] = 1LL * x * (r - l + 1);
			lazySet[id] = x;
			return;
		}
		int m = (l + r)/2;
		pushDown(id, l, r);
		set(id * 2, l, m, u, v, x);
		set(id * 2 + 1, m + 1, r, u, v, x);
		pullUp(id);
	}	
	void set(int l,int r,int x){
		set(1, 1, size, l, r, x);
	}
	ll get(int id,int l,int r,int u,int v){
		if(v < l || r < u) return 0LL;
		pushDown(id, l, r);
		if(u <= l && r <= v) return st[id];
		int m = (l + r)/2;
		return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
	}
	ll get(int l,int r){
		return get(1, 1, size, l, r);
	}
} st;
void solve(int id){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i] = i;
	st.init(n);
	ll prev = st.get(1, n);
	while(m--) {
		int l, r, x;
		cin >> l >> r >> x;
		st.set(l, r, x);
		ll cur = st.get(1, n);
		// cout << prev << ' ' << cur << nl;
		cout << abs(cur - prev) << nl;
		prev = cur;
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