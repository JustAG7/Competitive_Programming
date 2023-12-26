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
const int N = 1e3+5;
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


ll f[N][N];
struct DSU{
	vi par;

	void init(int n){
		par.resize(n + 2, 0);
		for(int i=1;i<=n;i++) par[i] = i;
	}

	int find_set(int u){
		return u == par[u] ? u : par[u] = find_set(par[u]);
	}

	bool join(int u,int v){
		u = find_set(u);
		v = find_set(v);
		if(u == v) return false;
		par[v] = u;
		return true;
	}
} dsu;

struct Edge {
    int u, v; ll c;
    Edge(int _u, int _v, ll _c): u(_u), v(_v), c(_c) {};
};
struct Component{
	int x1,x2,y1,y2;ll c;
	Component(int _x1,int _x2,int _y1,int _y2,ll _c): x1(_x1), x2(_x2), y1(_y1), y2(_y2), c(_c) {};
}
vector<Edge> edges;
vector<Component> components;
void solve(){
	int n,q;
	cin >> n >> q;
	ll ans = 0;
	while(q--){
		int imin,imax,jmin,jmax;ll w;
		cin >> imin >> imax >> jmin >> jmax >> w;
		components.pb({imin,imax,jmin,jmax,w});
	}

	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			edges.pb({i,j,f[i][j]});
		}
	}
	dsu.init(n);
	sort(all(edges), [](Edge &x, Edge &y){
		return x.c < y.c;
	});
	for(auto e : edges){
		// cout << u << ' ' << v << nl;
		if(!dsu.join(e.u, e.v)) continue;
		ans += e.c;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
