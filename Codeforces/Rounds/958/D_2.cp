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
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<vector<ll>> f(n, vector<ll>(25, 0));
	vector<ll> suf(25);
	for(auto &x : a) cin >> x;
	vector<vi> g(n);
	for(int i=1;i<n;i++){
		int u, v;
		cin >> u >> v;
		g[u - 1].pb(v - 1);
		g[v - 1].pb(u - 1);
	}
	auto dfs = [&](auto &&self, int u, int pre) -> void{
		for(int i=1;i<=22;i++) f[u][i] = i * a[u];
		for(auto v : g[u]){
			if(v == pre) continue;
			self(self, v, u);
			ll x = 1e18;
			suf[23] = 1e18;
			for(int i=22;i>=1;i--){
				suf[i] = min(suf[i + 1], f[v][i]);
			}
			for(int i=1;i<=22;i++){
				f[u][i] += min(x, suf[i + 1]);
				x = min(x, f[v][i]);
			}
		}
	};
	dfs(dfs, 0, -1);
	ll ans = 1e18;
	for(int i=1;i<=22;i++) ans = min(ans, f[0][i]);
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}