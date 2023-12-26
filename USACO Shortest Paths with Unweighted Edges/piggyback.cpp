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
	#define JA "piggyback"
	if(fopen(JA ".in", "r")){
		freopen(JA ".in","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int b,e,p,n,m;
vi g[N];
int dist[4][N];
int vis[4][N];
void bfs(int start,int res){
	vis[res][start] = 1;
	int val = res == 1 ? b : res == 2 ? e : p;
	queue<int> q;
	q.push(start);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(vis[res][v]) continue;
			dist[res][v] = dist[res][u] + val;
			vis[res][v] = 1;
			q.push(v);
		}
	}
}
void solve(){
	cin >> b >> e >> p >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	bfs(1, 1);
	bfs(2, 2);
	bfs(n, 3);

	int ans = M;
	for(int i=1;i<=n;i++){
		int tmp = dist[1][i] + dist[2][i] + dist[3][i];
		ans = min(ans, tmp);
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