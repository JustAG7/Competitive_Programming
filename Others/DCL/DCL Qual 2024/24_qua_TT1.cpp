#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define cst(T) const T&

template<class A, class B> bool umin(A& var, cst(B) val) {
	return (val < var) ? (var = val, true) : false;
}
template<class A, class B> bool umax(A& var, cst(B) val) {
	return (var < val) ? (var = val, true) : false;
}

typedef long long Int;
typedef long double Real;
const int MOD = 1e9 + 7;
void add(int &a, const int& b) { 
	if ((a+=b) >= MOD) a -= MOD; 
	if (a < 0) a += MOD;
}
int product(const int& a, const int& b) { return (Int)a*b % MOD; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << '\n';

int s1(Int n) { 
	Int a[2] = {n,n+1};
	a[n%2] /= 2;
	return product(a[0] % MOD, a[1] % MOD);
}
int s1(Int l, Int r) { return (s1(r) - s1(l-1) + MOD) % MOD; }
int s2(Int n) {
	Int a[3] = {n,n+1,2*n+1};
	for (int d : {2,3})
		for (int i = 0; i < 3; i++) if (a[i] % d == 0) { a[i] /= d; break; }
	int res = a[0] % MOD;
	for (int i = 1; i < 3; i++) res = product(res, a[i] % MOD);
	return res;
}
int s2(Int l, Int r) { return (s2(r) - s2(l-1) + MOD) % MOD; }

struct Node {
	int sum, coef[3], lazy[3];
	Node() : sum(0) {
		for (int i = 0; i < 3; i++) coef[i] = lazy[i] = 0;
	}
};
 
class TSegmentTree {
private : 
	int range;
	vector<Node> nodes;
	
	void build(int x, int l, int r) {
		nodes[x].sum = 0;
		if (l < r) {
			int m = (l+r) / 2;
			build(2 * x, l, m);
			build(2 * x + 1, m + 1, r);
 		}
		nodes[x].coef[0] = r-l+1; 
		nodes[x].coef[1] = s1(l,r); 
		nodes[x].coef[2] = s2(l,r); 
	}

	void apply(int x, int weight[3])  {
		for (int i = 0; i < 3; i++) {
			add(nodes[x].sum, product(weight[i], nodes[x].coef[i]));
			add(nodes[x].lazy[i], weight[i]);
		}
	}
	
	void push_down(int x) {
		for (int y : {2*x, 2*x+1})
			apply(y, nodes[x].lazy);
		for (int i = 0; i < 3; i++) nodes[x].lazy[i] = 0;
	}
	
	void range_update(int x, int l, int r, int L, int R, int weight[3]) {
		if (l > r or l > R or L > r or L > R) return ;
		if (L <= l and r <= R) return apply(x, weight);
		push_down(x);
		int m = (l+r) / 2;
		range_update(x * 2, l, m, L, R, weight);
		range_update(x * 2 + 1, m + 1, r, L, R, weight);
		nodes[x].sum = (nodes[2*x].sum + nodes[2*x + 1].sum) % MOD;
	}
	
	int query(int x, int l, int r, int L, int R) {
		if (l > r or l > R or L > r or L > R) return 0;
		if (L <= l and r <= R) return nodes[x].sum;
		int m = (l+r) / 2;
		push_down(x);
		return (query(x * 2, l, m, L, R) +
					query(x * 2 + 1, m + 1, r, L, R)) % MOD; 
	}
	#undef mid
public : 
	void init(int n) {
		range = n;
		nodes.resize(4 * range + 100);
		build(1, 1, range);
	}
	TSegmentTree(int size=1) { init(size); }
	void range_update(int l, int r, int val[3]) {
		range_update(1, 1, range, l, r, val);
	}
	int query(int l, int r) {
		return query(1, 1, range, l, r);
	}
} solver;
 

void solve(int testID) {
	int n, num_queries = 1;
	cin >> n;
	cin >> num_queries;
	solver.init(n);

	auto pos_add = [&] (int i, int a) {
		i += a;
		i %= n;
		if (i == 0) i += n;
		return i;
	};
	auto query = [&] (int l, int r, int k, int start) {
		start %= MOD;
		if (start < 0) start += MOD;
		int temp = product(n, product(k, k+1));
		int coef[3];
		coef[0] = product(start, start);
		coef[0] = product(coef[0], k+1);
		add(coef[0], (-1) * product(start, temp));
		add(coef[0], product(product(n,n), s2(k)));
		coef[1] = product(n,k);
		add(coef[1], -1 * product(2, start));
		coef[1] = product(coef[1], k+1);
		coef[2] = k+1;
		// cerr << "query ";
		// DBG(l) DBG(r) DBG(k) DBG(start)
		// cerr << ": [";
		// for (int i = 0; i < 3; i++) cerr << coef[i] << ' ';
		// cerr << "]\n";
		solver.range_update(l, r, coef);
	};

	for (int typ, a, b; num_queries --> 0; ) {
		typ = 1;
		cin >> typ;
		cin >> a >> b;
		if (typ == 1) {
			int l = a, k = b / n - 1, r = b % n;
			int m = pos_add(l,r);
			// DBG(l) DBG(k) DBGn(m)
			if (m != l) {
				if (m > l) {
					query(l, m-1, k+1, l-1);
				} else {
					query(l, n, k+1, l-1);
					query(1, m-1, k+1, l-1-n);
				}
			}
			if (m >= l) {
				query(m, n, k, l-1);
				query(1, l-1, k, l-1-n);
			} else {
				query(m, l-1, k, l-1-n);
			}

		}
		else cout << solver.query(a, b) << '\n';
	}
	// for (int i = 1; i <= n; i++) cout << solver.query(i,i) << ' ';
}


int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	#define task "WF"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
