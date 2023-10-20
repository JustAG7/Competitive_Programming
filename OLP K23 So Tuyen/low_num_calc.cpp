#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
const int N = 3e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int low[N],num[N];
int timeDfs = 0, bridge = 0;
vi g[N];
int joint[N],countNode[N];

void dfs(int u,int pre){
	int child = 0;
	low[u] = num[u] = ++timeDfs;
	countNode[u] = 1;
	for(int v : g[u]){
		if(v == pre) continue;
		if(!num[v]){
			dfs(v, u);
			countNode[u] += countNode[v];
			low[u] = min(low[u],low[v]);
			child++;
			if(low[v] > num[u]) bridge++;
			if(u == pre) if(child > 1) joint[u] = 1;
			else if(low[v] >= num[u]) joint[u] = 1;
		}
		else low[u] = min(low[u],num[v]);
	}

}
int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	for(int i=1;i<=n;i++){
		if(!num[i]) dfs(i,i);
	}
	for(int i=1;i<=n;i++) cout << i << ": " << low[i] << " time: " << num[i] << nl;cout << nl;
	for(int i=1;i<=n;i++) cout << i << ": " << countNode[i] << '\n';
}