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

vector<pair<int,int>> g[maxn];
int n,a,b;
set<int> s;
void clear(){
	s.clear();
	for(int i=0;i<n;i++) g[i].clear();
}
void dfs1(int u,int v,int x){
	if(u==b) return;
	s.insert(x);
	for(auto p : g[u]){
		int m = p.X, n= p.Y;
		if(m==v) continue;
		dfs1(m,u,x^n);
	}
}
bool dfs2(int u,int v,int x){
	if(u!=b && s.count(x)) return true;
	for(auto p : g[u]){
		int m = p.X, n= p.Y;
		if(m==v) continue;
		if(dfs2(m,u,n^x)) return true;
	}
	return false;
}
void solve(){
	cin >> n >> a >> b;
	a--;b--;
	clear();
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--;v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dfs1(a,-1,0);
	cout << ((dfs2(b,-1,0)) ? "YES" : "NO") << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}