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
#define vvi vector<vector<int>> 

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int n,m;
vi g[maxn];
vi ans;
int par[maxn];
void dfs(int u,int prev){
	for(int v : g[u]){
		if (v==prev) continue;
        if (par[v]){
            ans.pb(u);
            while (ans.back() != v) ans.pb(par[ans.back()]);            
            ans.pb(u);
            cout << ans.size() << nl;
            for (int x : ans) cout << x << ' ';            
            exit(0);
        }
        par[v]=u;
        dfs(v,u);
	}
}
int main(){
	fast;
	indef();
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!par[i]){
			par[i]=i;
			dfs(i,-1);
		}
	}
	cout << "IMPOSSIBLE";
}
