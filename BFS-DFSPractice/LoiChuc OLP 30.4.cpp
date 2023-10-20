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
vector<vector<int>> g(maxn,vector<int> (maxn,0));
vector<int> vis(maxn,0),mark(maxn,0);
void dfs(int i){
	vis[i]=1;
	for(int j=1;j<=n;j++){
		if(g[i][j] && !vis[j]) dfs(j);
	}
}
int main(){
	fast;
	indef();
	cin >> n >> m;
	int ans=0;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a][b]=1;
	}
	for(int i=0;i<n;i++){
		if(!vis[i]){
			mark[i]=1;
			dfs(i);
		}
	}
	fill(vis.begin()+1,vis.begin()+1+n,0);
	for(int i=1;i<=n;i++){
		if(mark[i] && !vis[i]){
			ans++;
			dfs(i);
		}
	}
	cout << ans;
}
