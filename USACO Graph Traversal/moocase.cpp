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
	#define JA "moocast"
	if(fopen(JA ".in", "r")){
		freopen(JA ".in","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
vector<int> g[205];

struct Cow{
	int x,y,c;
} a[205];
int vis[205];
int ans = 1, tmp = 0;
void dfs(int u){
	vis[u] = 1;
	tmp++;
	for(auto v : g[u]){
		if(!vis[v]) dfs(v);
	}
}
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].x >> a[i].y >> a[i].c;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int X = a[i].x - a[j].x, Y = a[i].y - a[j].y, Z = a[i].c;
			if((X*X) + (Y*Y) <= (Z*Z)) g[i].pb(j);
		}
	}
	for(int i=0;i<n;i++){
		tmp = 0;
		memset(vis,0,sizeof(vis));
		dfs(i);
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