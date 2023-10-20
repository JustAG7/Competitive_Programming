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
int n,m;
vector<int> g[maxn];
int vis[maxn],mark[maxn];
void dfs(int i){
	vis[i]=1;
	for(auto x : g[i]){
	    if(!vis[x]) dfs(x);
	}
}
int main(){
	fast;
	//indef();
	cin >> n >> m;
	int ans=0;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			mark[i]=1;
			dfs(i);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=n;i>=1;i--){
		if(mark[i] && !vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans;
}
