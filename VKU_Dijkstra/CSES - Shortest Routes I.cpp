#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define vi vector<int> 
#define vvi vector<vector<int>> 
#define vii vector<pair<int,int>>
#define ii pair<int,int>

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}


vii g[maxn];
int vis[maxn];
int n,m;
vi f(maxn,1e18);
struct cmp {
    bool operator()(const ii& a, const ii& b) {
        return a.Y > b.Y;
    }
};

void dijkstra(){
	f[1]=0;
	priority_queue<ii,vii,cmp> pq;
	pq.push(make_pair(1,0));
	while(!pq.empty()){
		auto p = pq.top();pq.pop();
		int u = p.X;
		if(vis[u]) continue;
		vis[u]=1;
		for(auto q : g[u]){
			int v = q.X;
			int w = q.Y;
			if(f[v]>f[u]+w){
				f[v]=f[u]+w;
				pq.push({v,f[v]});
			}
		}
	}
}
signed main(){
	fast;
	indef();

	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		g[u].pb({v,w});
	}
	dijkstra();
	for(int i=1;i<=n;i++) cout << f[i] << ' ';
}
