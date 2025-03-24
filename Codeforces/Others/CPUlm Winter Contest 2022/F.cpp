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

const int M=1e9+7;
const int maxn=2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vector<int> g[maxn];
vector<int> vis(maxn,0);

void dfs(int i){
	vis[i]=1;

}
void solve(){
	int n,m,ans=0;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i);
		}
	}
}
signed main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}