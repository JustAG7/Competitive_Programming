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
const int N = 1e5+5;
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
vector<pair<int,int>> g[N];
int par[N];
int n, m;
void clear() {
	for(int i=0;i<n;i++) par[i] = i;
}
int get(int u) {
	return u == par[u] ? u : par[u] = get(par[u]);
}
bool join(int u,int v) {
	u = get(u);
	v = get(v);
	if(u == v) return false;
	par[v] = u;
	return true;
}
void solve(){
	cin >> n >> m;
	clear();
	ll ans = 0;
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		pq.push({w, u, v});
	}
	while(pq.size()) {
		auto [w, u, v] = pq.top(); pq.pop();
		if(join(u, v)) {
			ans = max(ans, 1LL * w);
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}