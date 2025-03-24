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
#define ii pair<ll,ll>
const int M=1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int n,m;
vector<ii> g[N];
ll f[N];

void bfs(){
	priority_queue<ii ,vector<ii>, greater<ii> > pq;
	pq.push({1,0});
	while(!pq.empty()){
		auto [u,w] = pq.top();pq.pop();
		if(f[u] != w) continue;
		for(auto [v,p] : g[u]){
			if(max(f[u],p) < f[v]){
				pq.push({v,max(f[u],p)});
				f[v] = max(f[u],p);
			}
		}
	}
}
void solve(){
	memset(f,M,sizeof(f));
	f[1] = 0;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	bfs();
	cout << f[n];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
