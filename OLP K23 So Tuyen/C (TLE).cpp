#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);



const int N = 3e5+5;

long long ans = 0;
int n, m;
bool joint[N];
int timeDfs = 0, bridge = 0;
int low[N], num[N];
int cnt[N],vis[N];
vector <int> g[N];
 
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void dfs(int u, int pre) {
    int child = 0; 
    num[u] = low[u] = ++timeDfs;
    for (int v : g[u]) {
        if (v == pre) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) bridge++;
            child++;
            if (u == pre) { 
                if (child > 1) joint[u] = true;
            }
            else if (low[v] >= num[u]) joint[u] = true;
        }
        else low[u] = min(low[u], num[v]);
    }
}
void dfs2(int u,int par){
	vis[u] = 1;
	for(int v : g[u]){
		if(vis[v] || v == par) continue;
		dfs2(v, u);
		cnt[u] += cnt[v] + 1;
	}
}
int main() {
	fast;
	indef();
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) 
        if (!num[i]) dfs(i, i);

    for (int i = 1; i <= n; i++){
    	if(!joint[i]) cout << 0 << ' ';
    	else{
    		// cout << "joint " << i << '\n';
    		ans = 0;
    		for(int j=1;j<=n;j++) cnt[j] = vis[j] = 0;
    		vis[i] = 1;
    		vector<int> res;
    		for(int u : g[i]) if(!vis[u]){
    			res.push_back(u);
    			cnt[u] = 1;
    			dfs2(u,-1);
    		}
    		// for(int i=1;i<=n;i++) cout << cnt[i] << ' ';cout << '\n';
    		for(int l = 0;l < res.size() - 1;l++){
    			for(int r = l+1; r < res.size();r++){
    				ans+= (cnt[res[l]]) * (cnt[res[r]]) ;
    			}
    		}
    		cout << ans << ' ';
    	}
    	// cout << "done\n";
    }
}
