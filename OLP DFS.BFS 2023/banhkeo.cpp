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
vii g[N];
int vis[N];
int f[N];
int mx = INT_MAX;
void bfs(int x){
	vis[x] = 1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto [v,w] : g[u]){
			if(!vis[v] && w >= mx){
				vis[v] = 1;
				q.push(v);
				f[v] = 1;
			}
		}
	}

}
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	rep(i,0,k){
		int x;cin >> x;
		mx = min(mx,x);
	}
	rep(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	int ans = 0;
	rep(i,1,n+1){
		if(!vis[i]) bfs(i);
		if(!f[i]) ans++;
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