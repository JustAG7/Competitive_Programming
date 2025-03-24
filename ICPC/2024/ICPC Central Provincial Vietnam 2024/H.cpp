#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
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
#define cst(T) const T&
 
template<class A, class B> bool umin(A& var, cst(B) val) {
	return (val < var) ? (var = val, true) : false;
}
template<class A, class B> bool umax(A& var, cst(B) val) {
	return (var < val) ? (var = val, true) : false;
}
 
typedef long long Int;
typedef long double Real;
const int MOD = 2004010501;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << '\n';

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
const int M = 1e9+7;
// const ll inf = 1e18;
// const ll INF = 0x3f;
const int N = 2e5 + 50;
const int A = 20;
int n, a[N];

struct Node {
	int Max, sum;
	Node(int Max = 0, int sum = 0): Max(Max), sum(sum) {}
};
Node operator+ (cst(Node) L, cst(Node) R) {
	return Node(max(L.Max, R.Max), L.sum + R.sum);
}

const int T = 4 * N;
struct SegTree {
	int range;
	Node nodes[T];
	SegTree() {}
	void build(int x, int l, int r) {
		if (l == r) nodes[x] = {a[l], a[l]};
		else {
			int m = (l+r) / 2;
			build(2*x, l,m);
			build(2*x+1, m+1, r);
			nodes[x] = nodes[2*x] + nodes[2*x + 1];
		}
	}
	void init(int n) { range = n; build(1, 1, n); }
	void _update(int x, int l, int r, int pos, int v) {
		if (l == r) nodes[x] = {v,v};
		else {
			int m = (l+r) / 2;
			pos <= m ? _update(2*x, l,m, pos, v) : _update(2*x+1, m+1,r, pos, v);
			nodes[x] = nodes[2*x] + nodes[2*x + 1];
		}
	}

	void update(int pos, int val) {
		_update(1, 1,range, pos, val);
	}

	int _query_sum(int x, int l, int r, int L, int R) {
		if (l > r or l > R or L > r or L > R) return 0;
		if (L <= l && r <= R) return nodes[x].sum;
		int m = (l+r) / 2;
		return _query_sum(2*x, l,m, L,R) + _query_sum(2*x+1, m+1,r, L,R);
	}
	int query_sum(int l, int r) {
		return _query_sum(1, 1,range, l,r);
	}
	vector<array<int,3>> ranges;
	void _explore(int x, int l, int r, int L) {
		if (r < L) return ;
		if (l >= L) ranges.push_back({x,l,r});
		else {
			int m = (l+r) / 2;
			_explore(2*x, l,m, L);
			_explore(2*x+1, m+1,r, L);
		}
	}
	int _trace(int x, int l, int r, int val) {
		if (nodes[x].Max <= val) return -1;
		if (l == r) return r;
		int m = (l+r) / 2;
		int pre = _trace(2*x, l,m, val);
		if (pre == -1) return _trace(2*x+1, m+1,r, val); 
		return pre;
	}
	int query_nearest_greater(int L, int R, int val) {
		ranges.clear();
		_explore(1, 1,range, L);
		// cerr << "\nafter " << L << ": ";
		// for (auto [x,l,r] : ranges) cerr << "(" << l << ',' << r << ") ";
		// cerr << '\n';
		for (auto [x,l,r] : ranges)
			if (nodes[x].Max > val) {
				return _trace(x,l,r, val);
			}
		return -1;
	}
};
SegTree stroke_manager;

int fenwick[N], value[N], nxt_ckpt[N];
void update(int x, int delta) {
	for (; x <= n; x += x&-x) fenwick[x] += delta;
}
int query(int x) {
	int res  = 0;
	for ( ; x ; x &= x-1) res += fenwick[x];
	return res;
}
int query_range(int l, int r) {
	return query(r) - query(l - 1);
}

int calculate(int l, int r) {
	if (l > r) return 0;
	// cerr << "calculate(" << l << ',' << r << "): ";
	int levl = a[l];
	int res = 0;
	res -= stroke_manager.query_sum(l,r);
	while (l <= r) {
		// cerr << '(' << l << ',' << levl << ") ";
		int nxt = stroke_manager.query_nearest_greater(l+1, r, levl);
		if (nxt == -1) {
			res += levl * (r-l+1);
			break;
		}
		// cerr << "(add " << levl * (nxt-l) << ") ";
		res += levl * (nxt - l); // [l, nxt)
		l = nxt;
		levl = a[l];
	}
	// DBGn(res)
	return res;
}

// int answer_query(int l, int r) 
void refresh_ckpt_value(int l) {
	int r = nxt_ckpt[l];
	int new_value = calculate(l, r-1);
	int delta = new_value - value[l];
	if (delta) update(l, delta);
	value[l] = new_value;
}

void solve(int testID){
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i];
	stroke_manager.init(n);
	set<int> checkpoints;
	checkpoints.insert(1);
	checkpoints.insert(n + 1);
	nxt_ckpt[1] = n+1;
	value[1] = calculate(1, n);
	auto find_left_check_point = [&] (int i) {
		auto it = checkpoints.upper_bound(i);
		return *(--it);
	};
	while (q --> 0) {
		cerr << "QUERY\n";
		int typ,p,x,l,r;
		cin >> typ;
		if (typ == 1) {
			cin >> p >> x;
			stroke_manager.update(p, x);
			a[p] = x;
			l = find_left_check_point(p);
			refresh_ckpt_value(l);
		} else
		if (typ == 2) {
			cin >> p;
			p += 1;
			if (!checkpoints.count(p)) {
				l = find_left_check_point(p);
				r = nxt_ckpt[l];
				nxt_ckpt[l] = p;
				nxt_ckpt[p] = r;
				checkpoints.insert(p);
				refresh_ckpt_value(l);
				refresh_ckpt_value(p);
			}
		} else
		if (typ == 3) {
			cin >> l >> r;
			int last = find_left_check_point(r);
			int first = l > 1 ? find_left_check_point(l-1) : 1;
			if (first == 1 && checkpoints.count(1)) ;
			else first = nxt_ckpt[first];
			int res = query_range(first, last - 1);
			DBG(l) DBG(r) DBG(first) DBG(last) DBGn(res)
			res += calculate(last, r);
			res += calculate(l, first-1);
			cout << res << '\n';
		}
	}
}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3