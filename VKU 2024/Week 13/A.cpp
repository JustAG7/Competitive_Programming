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
queue<int> q;
vector<int> g[N];
int f[N];
bool vis[N];
int n, m, k;
void bfs(){
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(vis[v] == true) continue;
			f[v] = f[u] + 1;
			vis[v] = true;
			q.push(v);
		}
	}
}
void solve(){
	memset(f, 0x3f, sizeof(f));
	cin >> n;
	cin >> k;
	for(int i=0;i<k;i++){
		int x;cin >> x;
		q.push(x);
		vis[x] = true;
		f[x] = 0;
	}
	cin >> m;
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	for(int i=1;i<=n;i++) cout << f[i] << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}