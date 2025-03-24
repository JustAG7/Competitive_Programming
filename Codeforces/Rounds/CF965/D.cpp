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

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> dp(n + 1), d(n + 1, -1);
	for(int i=0;i<m;i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
	}
	for(int i=1;i<n;i++){
		g[i].pb(i + 1);
	}
	d[1] = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j : g[i]){
			dp[i] = max(dp[i], j - d[i] - 1);
		}
	}
	int tmp = 0;
	for(int i=1;i<n;i++){
		tmp = max(tmp, dp[i - 1]);
		if(tmp - i <= 0) cout << 1;
		else cout << 0;
	}
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}