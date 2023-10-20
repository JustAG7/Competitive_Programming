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
vi g[maxn];
int vis[maxn];
int f[maxn];
void bfs(){
	queue<int> q;
	vis[1]=1;
	q.push(1);
	f[1]=0;
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int v : g[u]){
			if(!vis[v]){
				vis[v]=1;
				f[v]=f[u]+1;
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
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		g[x].pb(y);
		g[x].pb(z);
		g[y].pb(x);
		g[z].pb(x);
	}
	bfs();
	for(int i=1;i<=n;i++){
		cout << f[i]+1 << nl;
	}
}
	