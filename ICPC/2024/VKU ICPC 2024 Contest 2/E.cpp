#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
// const int M = 1e9+7;

const int N = 205;
const int M = N*N;
int num_nodes, num_edges;
int from[M], to[M];
Int wei[M];
Int dis[N][N], cnt[N][N];
const ll PATH = 100;
// const int INF = 1e9;

struct Edge {
	int u,v; Int w;
	bool operator< (cst(Edge) rhs) const {
		return w < rhs.w;
	}
};

struct DSU {
	int lab[N];
	void init(int n) {
		for(int i = 1; i <= n; i++) lab[i] = i;
	}
	int find_root(int u) {
		return u == lab[u] ? u : lab[u] = find_root(lab[u]);
	}
	bool merge_set(int u, int v) {
		u = find_root(u), v = find_root(v);
		if (u == v) return false;
		lab[v] = u;
		return true;
	}
} dsu;

void solve(int test_id) {
//	cout << "Case #" << test_id << ": ";
	cin >> num_nodes >> num_edges;
	for (int u = 1; u <= num_nodes; u++)
		for (int v = 1; v <= num_nodes; v++)
			dis[u][v] = INF;
	for (int i = 1; i <= num_edges; i++) {
		int u,v;
		Int d;
		cin >> u >> v >> d;
		from[i] = u, to[i] = v; wei[i] = d;
		umin(dis[u][v], d);
		umin(dis[v][u], d);
		cnt[u][v] = cnt[v][u] = 1;
	}
	for (int m = 1; m <= num_nodes; m++)
		for (int u = 1; u <= num_nodes; u++)
			for (int v = 1; v <= num_nodes; v++)
				if (dis[u][m] < INF && dis[m][v] < INF) {
					if (umin(dis[u][v], dis[u][m] + dis[m][v]))
						cnt[u][v] = 0;
					if (dis[u][v] == dis[u][m] + dis[m][v])
						cnt[u][v] = min(PATH, cnt[u][v] + cnt[u][m] * cnt[m][v]);
				}
	// dsu.init(num_nodes + 3);
	// for (int u = 1; u <= num_nodes; u++)
	// 	for (int v = 1; v <= num_nodes; v++) {
	// 		DBG(u) DBG(v) DBG(dis[u][v]) DBGn(cnt[u][v])
	// 	}
	vector<Edge> edges;
	for (int i = 1; i <= num_edges; i++)
		if (wei[i] <= dis[from[i]][to[i]] && cnt[from[i]][to[i]] <= 1) 
			edges.push_back({from[i], to[i], wei[i]});

	int num_kept = 0;
	Int tot_length = 0;
	// sort(all(edges));
	for (auto [u,v,w] : edges) {
		// cout << u << ' ' << v << ' ' << w << '\n';
		// if (dsu.merge_set(u,v)) {
		// 	++num_kept;
		// 	tot_length += w;
		// }
		num_kept++;
		tot_length += w;
	}
	cout << num_kept << ' ' << tot_length;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3