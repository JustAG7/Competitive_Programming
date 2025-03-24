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
vi g[maxn];
int vis[maxn];
bool dfs(int x,int y){
	vis[x]=1;
	for(int u : g[x]){
		if(!vis[u]){
			if(u==y) return true;
			else if(dfs(u,y)) return true;
		}
	}
	return false;
}

int main(){
	fast;
	indef();
	int n,m,c;
	cin >> n >> m >> c;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int x,y;
	cin >> x >> y;
	cout << ((dfs(x,y)) ? 0 : c);
}
