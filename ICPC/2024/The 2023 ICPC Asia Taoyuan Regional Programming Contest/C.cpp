#include<bits/stdc++.h>
using namespace std;

/*BITWISE*/
#define mask(n) (1LL << (n))
#define testBit(n, bit) ((n) & mask(bit))
#define flipBit(n, bit) ((n) ^ mask(bit))
#define cntBit(n) (__builtin_popcountll(n))

/*SHORTCUTS*/
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define cst(T) const T&

template<class A, class B>
	bool umin(A& var, cst(B) val) {
		if (val < var) return var = val, true;
		return false;
	}
template<class A, class B>
	bool umax(A& var, cst(B) val) {
		if (var < val) return var = val, true;
		return false;
	}


/*NUMERICS*/
using ll = long long;
using ld = long double;
typedef long long Int;
typedef long double Real;
//typedef __int128 Big;
//const int MODS[] = {(int) 1e9+7, (int) 1e9+9, 998244353, 2004010501};
const int MOD = 2004010501;
void add(int& x, cst(int) y) {
	if ((x += y) >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}
int prod(cst(int) x, cst(int) y) { return ((Int)x*y) % MOD; }

const Real EPS = 1e-9;
bool equals(cst(Real) x, cst(Real) y) { return abs(x-y) <= EPS; }

/*DEBUGGING*/
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
//Usage
//TimeVar tBegin = timeNow();
//TimeVar tEnd = timeNow();
//Real measurement = duration(tEnd-tBegin);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << endl;

/*CONSTANTS*/
const Int INF = 1e18;
const Real PI = acos(-1);

const int N = 1e6 + 10;
int stt[N], p_init[N];

const int T = 4*N;
struct SegmentTree {
	SegmentTree() {}
	struct Node {
		int siz, cnt0, cnt1;
		Node() {}
		Node(int siz, int cnt0, int cnt1): siz(siz), cnt0(cnt0), cnt1(cnt1) {}
		void flip(void) { swap(cnt0, cnt1); }
		Node operator+ (cst(Node) o) const {
			return Node(siz + o.siz, cnt0 + o.cnt0, cnt1 + o.cnt1);
		}
	};
	int range;
	int lazy[T]; // 0/1 only, BOOL is SUCK
	Node nodes[T];
	void build(int x, int l, int r) {
		if (l == r) nodes[x] = Node(1, stt[l] == 0, stt[r] == 1);
		else {
			int m = (l+r) / 2;
			build(2*x, l,m);
			build(2*x+1, m+1,r);
			nodes[x] = nodes[2*x] + nodes[2*x + 1];
		}
	}

	void _apply_lazy(int x) {
		lazy[x] ^= 1;
		nodes[x].flip();
	}

	void _push_down(int x) {
		if (!lazy[x]) return ;
		for (int y : {2*x, 2*x+1}) _apply_lazy(y);
		lazy[x] ^= 1;
	}

	void _flip_range(int x, int l, int r, int L, int R) {
		if (l > r or L > R or l > R or L > r) return ;
		if (L <= l && r <= R) return _apply_lazy(x);
		int m = (l+r) / 2;
		_push_down(x);
		_flip_range(2*x, l,m, L,R);
		_flip_range(2*x+1, m+1,r, L,R);
		nodes[x] = nodes[2*x] + nodes[2*x + 1];
	}

	void flip_range(int l, int r) {
		_flip_range(1, 1,range, l,r);
	}

	int _query(int x, int l, int r, int L, int R) {
		if (l > r or L > R or l > R or L > r) return 0;
		if (L <= l && r <= R) return nodes[x].cnt1;
		_push_down(x);
		int m = (l+r) / 2;
		nodes[x] = nodes[2*x] + nodes[2*x+1];
		return _query(2*x, l,m, L,R) + _query(2*x+1, m+1,r, L,R);
	}

	int query(int l, int r) {
		return _query(1, 1,range, l,r);
	}

	void init(int n) {
		range = n;
		fill(lazy, lazy + 4*n + 1, 0);
		build(1, 1,range);
	}
} tree;

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
const int M = 1e9+7;

void solve(int test_id) {
//	cout << "Case #" << test_id << ": ";
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> stt[i] >> p_init[i];
	tree.init(n);
	Int ans = 0;
	for (int i = 1; i <= n; i++) ans += p_init[i];
	while (m --> 0) {
		char typ; cin >> typ;
		if (typ == 'W') {
			int l,r; cin >> l >> r;
			++l; ++r;
			tree.flip_range(l,r);
		} else {
			assert(typ == 'C');
			int q; cin >> q;
			int cnt = tree.query(1,n);
			ans += (Int) cnt * q;
		}
	}
	cout << ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3