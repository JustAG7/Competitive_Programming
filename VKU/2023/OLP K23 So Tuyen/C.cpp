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
int timeDfs = 0,bridge = 0;
vi g[N],res[N];
int countNode[N],root[N], joint[N];
int n,m;

void dfs(int u,int pre){
	int child = 0;
	low[u] = num[u] = ++timeDfs;
	countNode[u] = 1;
	for(int v : g[u]){
		if(v == pre) continue;
		if(!num[v]){
			root[v] = root[u];
			dfs(v, u);
			countNode[u] += countNode[v];
			low[u] = min(low[u],low[v]);
			child++;
			if(low[v] > num[u]) bridge++; // cau
			if(u == pre){
				if(child > 1) joint[u] = 1; // goc
				res[u].pb(countNode[v]);
			}
			else if(low[v] >= num[u]){
				res[u].pb(countNode[v]); // khop
				joint[u] = 1;
			}
		}
		else low[u] = min(low[u],num[v]);
	}
}
int main(){
	fast;
	indef();
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int u,v; cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	for(int i=1;i<=n;i++){
		if(!num[i]){
			root[i] = i;
			dfs(i,i);
		}
	}

	for(int i=1;i<=n;i++){
		if(!joint[i]) cout << "0 ";
		else{
			int tmp = countNode[root[i]] - 1;
			for(auto x : res[i]){
				tmp -= x;
			}
			if(tmp != 0) res[i].pb(tmp);
			ll ans = 0;
			ll sum = 0;
			for(auto x : res[i]) sum += x;
			for(auto x : res[i]){
				sum -= x;
				ans += x * sum;
			}
			cout << ans << ' ';
 		}
	}
}