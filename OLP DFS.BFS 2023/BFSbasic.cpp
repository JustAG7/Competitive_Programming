#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int f[N];
vi g[N];
vector<pair<int,int>> ans;
void bfs(int s){
	f[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(f[v] != -1) continue;
			f[v] = f[u] + 1;
			q.push(v);
		}
	}
}
void solve(){
	int n,m,s;
	cin >> n >> m >> s;
	memset(f,-1,sizeof(f));
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs(s);
	for(int i=1;i<=n;i++){
		if(f[i] != -1) ans.pb({f[i],i});
	}
	sort(all(ans));
	for(auto [u,v] : ans){
		cout << v << ' ' << u << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}