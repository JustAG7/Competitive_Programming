#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const int maxn=1e5+5;

std::vector<int> g[maxn];
std::vector<int> visit(maxn);
int ans=0;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void bfs(int i){
	ans++;
	std::queue<int> q;
	q.push(i);
	visit[i]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v : g[u]){
			if(!visit[v]){
				visit[v]=1;
				q.push(v);
			}
		}
	}
}
int main(){
	//fast;
	indef();
	int n,m;
	std::cin >> n >> m;
	while(m--){
		int u,v;
		std::cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		if(!visit[i]) bfs(i);
	}
	std::cout << ans;
}