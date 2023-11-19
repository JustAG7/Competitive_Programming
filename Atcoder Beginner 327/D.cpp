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
const int N = 3e5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

vi g[N];
int vis[N];
bool ok = true;
int res[N];
int a[N], b[N];
int n,m;
void dfs(int u,int x){
	res[u] = x;
	vis[u] = 1;
	for(auto v : g[u]){
		if(!vis[v]){
			dfs(v,1 - x);
		}
		else if(res[u] == res[v]){
				ok = false;
		}
	}
}

void solve(){
	cin >> n >> m;
	for(int i=0;i<m;i++) cin >> a[i];
	for(int i=0;i<m;i++){
		cin >> b[i];
		g[a[i]].pb(b[i]);
		g[b[i]].pb(a[i]);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,0);
	}
	cout << (ok ? "Yes\n" : "No\n");
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}