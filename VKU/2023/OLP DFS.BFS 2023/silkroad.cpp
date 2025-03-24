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
const int N = 1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};




void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
vector<pair<ll,int>> g[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq;
int vis[N];
ll f[N];
void dijkstra(int x){
	vis[x] = 1;
	f[x] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		auto [w,u] = pq.top();pq.pop();
		if(f[u] != w) continue;
		for(auto [val,v] : g[u]){
			if(max(f[u], val) < f[v]){
				f[v] = max(f[u], val);
				pq.push({f[v],v});
			}
		}
	}
}
void solve(){
	int n,m;
	cin >> n >> m;
	memset(f,M,sizeof(f));
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({w,v});
		g[v].pb({w,u});
	}
	dijkstra(1);
	cout << f[n] << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}