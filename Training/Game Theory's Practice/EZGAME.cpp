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
const int N = 5e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};




void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
void indef1(){
	if(fopen("EZGAME.inp", "r")){
		freopen("EZGAME.inp","r",stdin);
		freopen("EZGAME.out","w",stdout);	
	}
}
vector<pair<int,int>> g1[N],g2[N];
bool dp[N][N];
int vis[N][N];
bool dfs(int u){
	
	return false;
}
void solve(){
	int n,m,w,b;		
	cin >> n >> m >> w >> b;
	while(m--){
		int u,v;
		cin >> u >> v;
		g1[u].pb({v,1});
		g2[v].pb({u,1});
	}
	dfs1(w);
	
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}