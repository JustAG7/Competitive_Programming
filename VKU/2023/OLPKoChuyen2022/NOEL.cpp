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
vector<int> g[maxn];
vector<bool> vis(maxn);
int x,y;
void dfs(int i){
	vis[i]=true;
	x++;
	y+=g[i].size();
	for(auto j : g[i]){
		if(!vis[j]) dfs(j);
	}
}
int main(){
	fast;
	indef();
	int n,m,ans=0;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			x = y = 0;
			dfs(i);
			ans+=min(x,y/2);
		}
	}
	cout << ans;
}