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
vector<int> ans;
int par[maxn];
int y;
void calc(int x){
	if(x==par[x]){
		ans.pb(x);
		return;
	}
	ans.pb(x);
	x=par[x];
	calc(x);
}
void dfs(int x){
	vis[x]=1;
	if(x==y){
		calc(y);
		return;
	}
	for(int u : g[x]){
		if(!vis[u]){
			par[u]=x;
			dfs(u);
		}
	}
}
int main(){
	fast;
	indef();
	int n,m,x;
	cin >> n >> m >> x >> y;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	for(int i=1;i<=n;i++){
		sort(all(g[i]));
	}
	par[x]=x;
	dfs(x);
	reverse(all(ans));
	for(auto x : ans) cout << x << ' ';
}
