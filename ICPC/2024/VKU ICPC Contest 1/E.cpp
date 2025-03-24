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
const ll inf = 1e18;
// const ll INF = 0x3f;
const int INF = 1e9;

const int N = 105;
const int V = 2*N*N;
int id_counter;
int node_id[N][N];
int rep_col[N], rep_row[N];


vector<int> adj[V];
int weight[V];
vector<int> dist[V];

struct State {
	int node, weight;
	State(int node, int weight): node(node), weight(weight) {}
	bool operator< (cst(State) rhs) const {
		return weight > rhs.weight;
	}
};

void sssp(int src) {
	priority_queue<State> heap;
	dist[src].assign(id_counter+1, INF);
	heap.push(State(src, 0));
	dist[src][src] = 0;
	while (!heap.empty()) {
		auto [u,wu] = heap.top(); heap.pop();
		for (auto v : adj[u]) {
			int relax = wu + weight[v];
			if (umin(dist[src][v], relax))
				heap.push(State(v, relax));
		}
	}
}

void solve(int testID)
{
	int nrows, ncols;
	cin >> nrows >> ncols;
	::id_counter = 0;
	memset(weight, 0, sizeof(weight));
	for (int i = 1; i <= nrows; i++) {
		for (int j = 1; j <= ncols; j++) {
			node_id[i][j] = ++id_counter;
			cin >> weight[id_counter];
		}
	}
	for (int i = 1; i <= nrows; i++) {
		rep_row[i] = ++id_counter;
		for (int j = 1; j <= ncols; j++)
			adj[rep_row[i]].push_back(node_id[i][j]);
	}
	for (int j = 1; j <= ncols; j++) {
		rep_col[j] = ++id_counter;
		for (int i = 1; i <= nrows; i++)
			adj[rep_col[j]].push_back(node_id[i][j]);
	}
	for (int i = 1; i < nrows; i++)
		adj[rep_row[i]].push_back(rep_row[i+1]);
	for (int i = 1; i < ncols; i++)
		adj[rep_col[i]].push_back(rep_col[i+1]);

	for (int i = 1; i <= nrows; i++)
		for (int j = 1; j <= ncols; j++) {
			if (i < nrows) adj[node_id[i][j]].push_back(rep_row[i+1]);
			if (j < ncols) adj[node_id[i][j]].push_back(rep_col[j+1]);
		}

	// ****************
	for (int i = 1; i <= nrows; i++) sssp(rep_row[i]);
	for (int j = 1; j <= ncols; j++) sssp(rep_col[j]);
	// ********
	int q; cin >> q;
	while (q --> 0) {
		int x,y, u,v;
		cin >> x >> y >> u >> v;
		int p = node_id[x][y], q = node_id[u][v];
		int ans = INF;
		for (auto w : adj[p]) umin(ans, dist[w][q]);
		cout << ans << '\n';
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