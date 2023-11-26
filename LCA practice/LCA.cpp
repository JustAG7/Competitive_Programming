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
int n;
vi g[N];
int up[N][10];
int h[N];
int lca(int u,int v){
	if(h[u] != h[v]){
		if(h[u] < h[v]) swap(u,v);

		int k = h[u] - h[v];

		for(int i=0;(1 << i) <= k;i++){
			if(k >> i & 1){
				u = up[u][i];
			}
		}
	}

	if(u == v) return u;

	int k = __lg(h[u]);
	for(int i=k;i>=0;i--){
		if(up[u][i] != up[v][i]){
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}
void dfs(int u){
	for(int v : g[u]){
		if(v == up[u][0]) continue;
		h[v] = h[u] + 1;

		up[v][0] = u;
		for(int i=1;i<10;i++){
			up[v][i] = up[up[v][i - 1]][i - 1];
		}
		dfs(v);
	}
}
void newTest(){
	for(int i=0;i<=n;i++) g[i].clear();
	memset(up,0,sizeof(up));
	memset(h,0,sizeof(h));
}
void solve(int testcase){
	cin >> n;
	newTest();
	for(int u=1;u<=n;u++){
		int m;
		cin >> m;
		for(int j=0;j<m;j++){
			int v;
			cin >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	dfs(1);
	int q;
	cin >> q;
	cout << "Case " << testcase << ":\n";
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << lca(u, v) << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int testcase=1;testcase<=tt;testcase++) solve(testcase);
}