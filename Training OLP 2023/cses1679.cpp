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
vi g[N], ans;
int vis[N], visCycle[N];
void dfs(int u){
	vis[u] = 1;
	for(auto v : g[u]){
		if(!vis[v]) dfs(v);
	}
	ans.pb(u);
}
int cycle(int u){
	visCycle[u] = 1;
	for(auto v : g[u]){
		if(!visCycle[v]) {if(cycle(v)) return 1;}
		else if(visCycle[v] == 1) return 1;
	}
	visCycle[u] = -1;
	return 0;
}
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(!visCycle[i] && cycle(i)) return cout << "IMPOSSIBLE",void();
		if(!vis[i]) dfs(i);
	}
	for(auto x : ans) cout << x << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}