#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>

const int M=1e9+7;
const int N = 1005;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

vector<int> g[N];
int par[N];
int f[N][N];
int n,m,k;
vector<ii> couples;
bool bfs(){
	memset(par,-1,sizeof(par));
	queue<int> q;
	q.push(0);
	par[0]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(par[v] != -1) continue;
			if(f[u][v]){
				par[v] = u;
				if(v == n+m+1) return true;
				q.push(v);
			}
		}
	}
	return false;
}
void solve(){
	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		int u,v;
		cin >> u >> v;
		v+=n;
		if(f[u][v]) continue;
		f[u][v] = 1;
		g[u].pb(v);
		g[v].pb(u);
		couples.pb({u,v});
	}
	for(int i=1;i<=n;i++){
		f[0][i]++;
		g[0].pb(i);
		g[i].pb(0);
	}
	for(int i=n+1;i<=n+m;i++){
		int tmp = n+m+1;
		f[i][tmp]++;
		g[tmp].pb(i);
		g[i].pb(tmp);
	}
	int cnt = 0;
	while(bfs()){
		cnt++;
		int v = n+m+1;
		while(v!=0){
			int u = par[v];
			f[u][v]--;
			f[v][u]++;
			v = par[v];
		}
	}

	cout << cnt << nl;
	for(auto couple : couples){
		auto [u,v] = couple;
		if(!f[u][v]){
			cout << u << ' ' << v-n << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
