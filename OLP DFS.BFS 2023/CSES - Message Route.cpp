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
int par[N];
vi g[N];
void bfs(){
	par[1] = 1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(par[v]) continue;
			par[v] = u;
			q.push(v);
		}
	}
}
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	bfs();
	if(!par[n]) cout << "IMPOSSIBLE";
	else{
		vi ans;
		int tmp = n;
		while(tmp != 1){
			ans.pb(tmp);
			tmp = par[tmp];
		}
		ans.pb(1);
		cout << ans.size() << nl;
		reverse(all(ans));
		for(auto x : ans) cout << x << ' ';
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}