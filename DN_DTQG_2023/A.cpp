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


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

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
int n,m;
struct Edge{
	int u,v,c,index;
};
struct DSU{
	vector<int> par;

	void init(int n){
		par.resize(n + 5,0);
		for(int i=1;i<=n;i++) par[i] = i;
	}

	int find_set(int u){
		return u == par[u] ? u : par[u] = find_set(par[u]);
	}

	bool union_set(int u,int v){
		u = find_set(u);
		v = find_set(v);
		if(u == v) return false;
		par[v] = u;
		return true;
	}
} dsu;
int vis[N];
vector<Edge> edges;
void solve(){
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		Edge edge;
		cin >> edge.u >> edge.v >> edge.c;
		edge.c %= 2;
		edge.index = i;
		edges.pb(edge);
	}
	dsu.init(n);
	int ans = 0;
	sort(all(edges),[](Edge &x,Edge &y){
		return x.c % 2 != y.c % 2;
	});
	vector<int> res;
	for(auto e : edges){
		if(!dsu.union_set(e.u, e.v)) continue;
		vis[e.u] = 1;
		vis[e.v] = 1;
		ans += e.c;
		res.pb(e.index);
	}
	// cout << ans;
	if(ans % 2 == 0){
		cout << "YES\n";
		for(auto x : res) cout << x << ' ';
		return;
	}
	cout << ans;
	for(auto e : edges){
		if(!vis[e.u] || !vis[e.v] && e.c&1){
			res.pb(e.index);
			cout << "YES\n";
			for(auto x : res) cout << x << ' ';
		}
	}
	cout << "NO\n";
}

int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}