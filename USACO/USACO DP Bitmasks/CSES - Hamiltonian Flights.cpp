
#pragma GCC optimize("O3")
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
const int N = 20;
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
int dp[1 << N][N];
int n, m;
vector<int> g[N];
void solve(int id){
	cin >> n >> m;
	for(int i=1;i<=m;i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v);
	}
	dp[1][0] = 1;
	for(int i=0;i<(1 << n);i++) {
		for(int u = 0; u < n; u++) {
			for(auto v : g[u]) {
				if(!dp[i][u] || i & (1 << v)) continue;
				dp[i | (1 << v)][v] += dp[i][u];
				dp[i | (1 << v)][v] %= M;
			}
		}
	}
	cout << dp[(1 << n) - 1][n - 1];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}