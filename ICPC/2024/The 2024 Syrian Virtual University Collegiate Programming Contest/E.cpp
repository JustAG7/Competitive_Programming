#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
vector<int> g[N];
bool vis[N];
int ans = M, f[N], cnt[N];
int bfs(int u, int k) {
	queue<int> q;
	k -= 1;
	vis[u] = 1;
	q.push(u);
	f[u] = 0;
	if (k <= 0) return f[u];
	while(q.size() && k > 0) {
		int u = q.front(); q.pop();
		++cnt[f[u]];
		for(auto v : g[u]) {
			if (vis[v]) continue;
			f[v] = f[u] + 1;
			vis[v] = 1;
			q.push(v);
			if ((--k) <= 0) return f[v];
		}
	}
	return -1;
}

void solve(int id){
	int n, k;
	cin >> n >> k;
	for(int i=0;i<n-1;i++) {
		int u, v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			vis[j] = false;
			f[j] = 0;
		}
		int rad = bfs(i, k);
		int re = 2 * rad;
		if (cnt[rad-1] >= 2) ++re;
		ans = min(ans, re);
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}