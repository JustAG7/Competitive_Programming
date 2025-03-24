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
	#define JA "pails"
	if(fopen(JA ".in", "r")){
		freopen(JA ".in","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int x,y,k,m;
int ans = M;
int vis[105][105][105];
void dfs(int u,int v,int op){
	if(vis[u][v][op] || op > k) return;
	ans = min(ans, abs(u + v - m));
	vis[u][v][op] = 1;
	dfs(0,v,op+1);
	dfs(u,0,op+1);

	dfs(x,v,op+1);
	dfs(u,y,op+1);

	dfs(max(u + v - y,0), min(u + v,y), op + 1);
	dfs(min(u + v, x), max(u + v - x, 0), op + 1);
}
void solve(){
	cin >> x >> y >> k >> m;
	dfs(0,0,0);
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}