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
int mx = INT_MAX;
int f[maxn];
vector<pair<int,int>> g[maxn];
int vis[maxn];
queue<int> q;
void bfs(int i){
	vis[i]=1;
	q.push(i);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto p : g[u]){
			int a = p.X, b = p.Y;
			if(!vis[a] && b>=mx){
				f[a]=1;
				vis[a]=1;
				q.push(a);
			}
		}
	}
}
int main(){
	fast;
	indef();
	int n,m,k;	
	cin >> n >> m >> k;
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		mx=min(x,mx);
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		g[x].pb({y,z});
		g[y].pb({x,z});
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]) bfs(i);
		if(f[i]==0) ans++;
	}
	cout << ans;
}
