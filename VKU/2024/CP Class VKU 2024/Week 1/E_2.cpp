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
vector<int> g[N], ans;
bool vis[N];

void bfs(int x){
	queue<int> q;
	q.push(x);
	ans.pb(x);
	vis[x] = 1;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(vis[v]) continue;
			ans.pb(v);
			q.push(v);
			vis[v] = 1;
		}
	}
}
void solve(){
	int n;
	cin >> n;
	vector<int> res;
	for(int i=1;i<=n;i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(i);
		g[v].pb(i);
		if(i == u || i == v) res.pb(i);
	}
	for(auto x : res){
		if(vis[x]) continue;
		bfs(x);
	}
	if(ans.size() != n) return cout << -1, void();
	reverse(all(ans));
	for(auto x : ans) cout << x << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}