#include<bits/stdc++.h>
using namespace std;
#define int long long
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
vi f(maxn,1e18);
queue<int> q;
void bfs(int x){
	f[x] = 0;
    q.push(x);
    vis[x] = 1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (auto v : g[u]){
            if(!vis[v]){
	            f[v] = min(f[v], f[u] + 1);
	            q.push(v);
	            vis[v] = 1;
        	}
        }
    }

}
signed main(){
	fast;
	indef();
	int n,m,s;
	cin >> n >> m >> s;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	bfs(s);
	vector<pair<int,int>> ans;
	for(int i=1;i<=n;i++){
		ans.pb({f[i],i});
	}

	sort(all(ans));
	for(auto p : ans){
		if(p.X==1e18) continue;
		cout << p.Y << ' ' << p.X << nl;
	}
}
