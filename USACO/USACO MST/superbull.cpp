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
const int N = 2e3+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "superbull"
	if(fopen(JA ".in", "r")){
		freopen(JA ".in","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

struct Edge{
	ll u,v,c;
	Edge(ll _u,ll _v,ll _c): u(_u), v(_v), c(_c) {}
};
vector<Edge> edges;
int a[N];
int par[N];

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
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		par[i] = i;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			edges.pb({i,j,a[i] ^ a[j]});
		}
	}
	sort(all(edges), [](Edge &x, Edge &y){
		return x.c > y.c;
	});
	ll ans = 0;
	for(auto e : edges){
		if(!union_set(e.u, e.v)) continue;
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