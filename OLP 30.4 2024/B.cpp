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
const int N = 5e5+5;
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
vi g[N];
vector<set<int>> res(N);
int id[N];
int cnt[N];
int check[N];
int n, m, k;
void dfs(int u,int nid){
	id[u] = nid;
	for(auto v : g[u]){
		if(id[v]) continue;
		dfs(v, nid);
	}
}
void solve(){
	cin >> n >> m >> k;
	while(m--){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1,nid = 1;i<=n;i++){
		if(id[i]) continue;
		dfs(i, nid);
		nid++;
	}
	for(int i=1;i<=n;i++) cnt[id[i]]++;      
	
	for(int i=0;i<=n;i++){
		res[(int)g[i].size()].insert(id[i]);
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
		vector<int> a;
		for(auto x : res[i]) a.pb(cnt[x]);
		sort(rall(a)); 
		int tmp = 0;
		for(int j=0;j<min((int)a.size(),k);j++){
			tmp += a[j];
		}
		ans = max(ans, tmp);
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