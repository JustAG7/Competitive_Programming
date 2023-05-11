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
#define vi vector<int> 

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int vis[maxn];
vi g[maxn];
vi ans;
vi f(maxn,0);
int par[maxn];
queue<int> q;
void bfs(){
	vis[1]=1;
	q.push(1);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int v : g[u]){
			if(!vis[v]){
				f[v]=f[u]+1;
				vis[v]=1;
				par[v]=u;
				q.push(v);
			}
		}
	}
}
int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	bfs();
	if(!vis[n]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	m=f[n]+1;
	for(int i=0;i<m;i++){
		ans.pb(n);
		n=par[n];
	}
	reverse(all(ans));
	cout << ans.size() << nl;
	for(int x : ans) cout << x << ' ';
}
