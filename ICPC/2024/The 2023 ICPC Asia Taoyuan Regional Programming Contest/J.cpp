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

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << endl;

/*CONSTANTS*/
const int INF = 1e9;
const Real PI = acos(-1);

const int M = 1e9+7;

const int N = 105;
int num_jobs, num_tranmissions;
int w_node[N], w_edge[N][N];

vector<int> split(string s, char delim) {
	s += delim;
	vector<int> res;
	for (int i = 0, num = 0; i < int(s.size()); i++) {
		if (s[i] == delim) {
			res.pb(num);
			num = 0;
		}
		else {
			num *= 10;
			num += (s[i] - '0');
		}
	}
	return res;
}

vector<int> adj[N], dag[N];
int label[N][N], trace[N][N];

int cnt[N]; // dp DAG
const int INIT = -1;
int count(int u) {
	int &res = cnt[u];
	if (res != INIT) return res;
	res = 0;
	for (auto v : dag[u]) res += count(v);
	umin(res, 2);
	return res;
}

void dijkstra_and_dag(int src) {
	#define dis label[src]
	for (int u = 1; u <= num_jobs; u++) {
		dis[u] = 0;
		dag[u].clear();
	}
	struct State {
		int node, wei;
		bool operator< (cst(State) o) const {
			return wei < o.wei;
		}
	};
	priority_queue<State> heap;
	heap.push({src, w_node[src]});
	dis[src] = w_node[src];
	while (!heap.empty()) {
		auto [u,w] = heap.top(); heap.pop();
		if (dis[u] != w) continue;
		for (auto v : adj[u]) {
			int rel = w + w_edge[u][v] + w_node[v];
			// cerr << "\t"; DBG(u) DBG(v) DBG(w_edge[u][v]) DBGn(rel)
			if (umax(dis[v], rel)) {
				heap.push({v, rel});
				trace[src][v] = u;
			}
		}
	}
	for (int u = 1; u <= num_jobs; u++) {
		for (auto v : adj[u]) if (dis[v] < INF)
			if (dis[u] + w_edge[u][v] + w_node[v] == dis[v]) {
				dag[v].push_back(u);
				// cerr << "\t(" << u << ',' << v << ")";
			}
	}
	// cerr << '\n';
	#undef dis
}

void trace_path(int u, int v, int last) {
	if (u == v) {
		cout << u-1; 
		cout << ",\n"[u == last];
		return ;
	}
	int w = trace[u][v];
	trace_path(u,w, last);
	cout << v-1;
	cout << ",\n"[v == last];
}

using Info = pair<int,int>;
void update(Info& var, cst(Info) val) {
	if (val.first > var.first) var = val;
	else if (val.first == var.first) var.second = min(2, var.second + val.second);
}

void solve(int test_id) {
	while (cin >> ::num_jobs >> ::num_tranmissions) {
		for (int u = 0; u <= num_jobs; u++)
			for (int v = 0; v <= num_jobs; v++) w_edge[u][v] = INF;
		string w_node_line;
		cin >> w_node_line;
		auto vec_w = split(w_node_line, ',');
		for (int i = 1; i <= num_jobs; i++) {
			w_node[i] = vec_w[i-1];
			// DBG(i) DBGn(w_node[i])
			adj[i].clear();
		}
		for (int i = 1; i <= num_tranmissions; i++) {
			int u,v, w;
			cin >> u >> v >> w;
			++u; ++v;
			umin(w_edge[u][v], w);
			adj[u].push_back(v);
		}
		int src = -1, dest = -1;
		Info lead(0,0);
		for (int u = 1; u <= num_jobs; u++) {
			dijkstra_and_dag(u);
			fill(cnt, cnt + 1 + num_jobs, INIT);
			cnt[u] = 1;

			for (int v = 1; v <= num_jobs; v++) {
				if (label[u][v] >= INF) continue;
				update(lead, {label[u][v], ::count(v)});
				if (lead.first == label[u][v]) {
					src = u; dest = v;
				}
			}
		}
		cout << lead.first << ',';
		if (lead.second > 1) cout << "M\n";
		else {
			trace_path(src, dest, dest);
		}
	}
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