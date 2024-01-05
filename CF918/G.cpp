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
#define tp tuple<ll,ll,ll>


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

void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,ll>>> g(n + 1);
	vector<ll> a(n + 1);
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	for(int i=1;i<=n;i++) cin >> a[i];
	vector<vector<ll>> f(n + 1,vector<ll> (1005, inf));
	vector<vector<int>> vis(n + 1,vector<int> (1005, 0));

	priority_queue<tp, vector<tp>, greater<tp>> pq;
	f[1][a[1]] = 0;
	pq.push({0LL, 1LL, a[1]}); // value, vertex, bike
	while(!pq.empty()){
		auto [d, u, s] = pq.top();pq.pop();
		if(vis[u][s] || f[u][s] == inf) continue;
		vis[u][s] = 1;
		for(auto [v, w] : g[u]){
			ll newS = min(a[v], s);
			if(f[v][newS] > f[u][s] + w * s){
				f[v][newS] = f[u][s] + w * s;
				pq.push({f[v][newS], v, newS});
			}
		}
	}
	ll ans = inf;
	for(int i=1;i<=1000;i++){
		ans = min(ans, f[n][i]);
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}