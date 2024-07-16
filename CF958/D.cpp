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
int n;
vector<int> g[N];
ll dp1[N], dp2[N], a[N];
int flag[N];
void clear(){
	for(int i=1;i<=n;i++){
		g[i].clear();
		dp1[i] = 0;
		dp2[i] = 0;
	}

}
void dfs1(int u,int pre){
	ll sum1 = 0, sum2 = 0;
	for(auto v : g[u]){
		if(v == pre) continue;
		dfs1(v, u);
		sum1 += dp2[v];
		sum2 += max(dp1[v], dp2[v]);
	}
	dp1[u] = a[u] + sum1;
	dp2[u] = sum2; 
	if(dp1[u] >= dp2[u]) flag[u] = 1;
	else flag[u] = 2;
}
void dfs2(int u,int pre){
	if(flag[u] == 1){
        a[u] = -1;
        for(auto v : g[u]){
            if(v == pre) continue;
            for(auto z : g[v]){
            	if(z == u) continue;
            	dfs2(z, v);
            }
        }
    } else {
        for(auto v : g[u]){
            if(v == pre) continue;
            dfs2(v, u);
        }
    }
}
void solve(){
	cin >> n;
	clear();
	ll sum = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum += a[i];
	}
	ll ans = 0;
	for(int i=0;i<n-1;i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=0;i<20;i++){
		ans += sum;
		for(int j=1;j<=n;j++) dp1[j] = dp2[j] = flag[j] = 0;

		dfs1(1, 0);
		// for(int j=1;j<=n;j++) cout << flag[j] << ' ';cout << nl;
		sum -= max(dp1[1], dp2[1]);
		dfs2(1, 0);
		// for(int j=1;j<=n;j++) cout << a[j] << ' ';
		// cout << nl;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}