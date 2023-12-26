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
const int N = 105;
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
vii g[N];
int f[N], par[N];
void solve(){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for(int i=1;i<=n;i++) f[i] = M, par[i] = 0;
	int t,u,v;
	cin >> t >> u >> v;
	if(t == 0){
		f[u] = 0;
		pq.push({0, u});
		while(!pq.empty()){
			auto [w, u] = pq.top();pq.pop();
			if(f[u] != w) continue;
			for(auto [v, val] : g[u]){
				if(f[v] > f[u] + val){
					f[v] = f[u] + val;
					pq.push({f[v], v});
				}
			}
		}
		cout << f[v] << nl;
	}
	else{
		
		f[u] = 0, par[u] = u;
		pq.push({0, u});
		while(!pq.empty()){
			auto [w, u] = pq.top();pq.pop();
			if(f[u] != w) continue;
			for(auto [v, val] : g[u]){
				if(f[v] > f[u] + val){
					f[v] = f[u] + val;
					par[v] = u;
					pq.push({f[v], v});
				}
			}
		}
		vi ans;
		while(v != u){
			ans.pb(v);
			v = par[v];
		}
		ans.pb(u);
		reverse(all(ans));
		cout << ans.size() << ' ';
		for(auto x : ans) cout << x << ' ';
		cout << nl;
	}
}
int main(){
	fast;
	indef();

	int tt=1;
	cin >> n >> m >> tt;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	while(tt--) solve();
}