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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vi g[N];
int vis[N];
vi ans;
void dfs(int u){
	vis[u] = 1;
	for(auto v : g[u]){
		if(!vis[v]) dfs(v);
	}
}
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			ans.pb(i);
			dfs(i);
		}
	}
	cout << ans.size() - 1 << nl;
	for(auto x : ans){
		if(x == 1) continue;
		cout << 1 << ' ' << x << nl;
	}

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}