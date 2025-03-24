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
const int N = 1e5+5;
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
vector<pair<int,ll>> g1[N];
vector<pair<int,ll>> g2[N];
ll f1[N], f2[N];
ll mx = 0;
int n,m;
struct Edge{
	ll x,y,c;
};
vector<Edge> edges;
void pfs1(){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	memset(f1, INF, sizeof(f1));
	pq.push({0, 1});
	f1[1] = 0;
	while(!pq.empty()){
		auto [w, u] = pq.top();pq.pop();
		if(f1[u] != w) continue;
		for(auto [v, val] : g1[u]){
			if(f1[u] + val < f1[v]){
				f1[v] = f1[u] + val;
				pq.push({f1[v], v});
			}
		}
	}
}
void pfs2(){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	memset(f2, INF, sizeof(f2));
	pq.push({0, n});
	f2[n] = 0;
	while(!pq.empty()){
		auto [w, u] = pq.top();pq.pop();
		if(f2[u] != w) continue;
		for(auto [v, val] : g2[u]){
			if(f2[u] + val < f2[v]){
				f2[v] = f2[u] + val;
				pq.push({f2[v], v});
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	ll ans = inf;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		Edge a;
		a.x = u, a.y = v, a.c = w;
		edges.pb(a);
		g1[u].pb({v, w});
		g2[v].pb({u, w});
	}
	pfs1();pfs2();
	for(auto e : edges){
		ans = min(ans, f1[e.x] + f2[e.y] + e.c/2);
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