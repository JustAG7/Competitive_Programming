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
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 5e3+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}




int a[N], n, t;
vi g[200005];
int par[200005];

void bfs(int x,int y){
	par[x] = x;
	queue<int> q;
	q.push(x);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(auto v : g[u]){
			if(!par[v]){
				par[v] = u;
				q.push(v);
			}
		}
	}
}
ii get(int x,int y){
	int dist = 0, h = a[y];
	while(y != x){
		h = max(h, a[y]);
		dist++;
		y = par[y];
	}
	h = max(h, a[x]);
	return {dist, h};
}
void clear(){
	for(int i=1;i<=n;i++) par[i] = 0;
}
void solve(){
	cin >> n >> t;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++){
		int u,v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);

	}
	ll ans = 0;
	for(int i=1;i<=n-2;i++){
		for(int j=i+1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				ll tmp = 0;

				bfs(i,j);
				auto p = get(i, j);
				clear();
				if(p.Y > t) continue;
				tmp += p.X;

				bfs(j,k);
				auto q = get(j, k);
				clear();
				if(q.Y > t) continue;
				tmp += q.X;

				bfs(k,i);
				auto w = get(k, i);
				clear();
				if(w.Y > t) continue;
				tmp += w.X;

				if(max({p.Y,q.Y,w.Y}) == t) ans += tmp;
			}
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}