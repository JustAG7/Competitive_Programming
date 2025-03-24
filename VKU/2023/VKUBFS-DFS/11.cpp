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
#define vvi vector<vector<int>> 

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

int par[maxn];
int vis[maxn];
vi g[maxn];
int x,y;
vi ans;
void calc(){
	if(y==par[y]){
		ans.pb(y);
		return;
	}
	ans.pb(y);
	y=par[y];
	calc();
}
void bfs(){
	vis[x]=1;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int v : g[u]){
			if(v==y){
				par[y]=u;
				return calc();
			}
			if(!vis[v]){
				par[v]=u;
				q.push(v);
				vis[v]=1;
			}
		}
	}
}
int main(){
	fast;
	int n,m;
	cin >> n >> m >> x >> y;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	for(int i=1;i<=n;i++){
		sort(all(g[i]));
	}
	par[x]=x;
	bfs();
	reverse(all(ans));
	for(int x : ans) cout << x << ' ';
}
