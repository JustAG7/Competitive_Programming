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

int n, m;
ll st[4 * N], a[N], dp[N];

void update(int id,int l,int r,int u, ll val){
	if(r < u || u < l) return;
	if(l == r){
		st[id] = val;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, u, val);
	update(id * 2 + 1,m + 1, r, u, val);
	st[id] = min(st[id * 2], st[id * 2 + 1]);
}
ll get(int id,int l,int r,int u,int v){
	if(v < l || r < u) return 1e18;
	if(u <= l && r <= v) return st[id];
	int m = (l + r)/2;
	return min(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}
void solve(){
	vector<tuple<int,int,ll>> a;
	cin >> n >> m;
	for(int i=1;i<=n+1;i++) dp[i] = 1e18;
	for(int i=1;i<=4 * n;i++) st[i] = 1e18;
	for(int i=0;i<m;i++){
		int x, y, w;
		cin >> x >> y >> w;
		if(x <= y)
			a.pb({x + 1, min(y + 1, n + 1), w});

	}
	sort(all(a));
	
	for(auto [x, y, w] : a){
		if(x == 1){
			dp[y] = min(dp[y], w);
			dp[x] = min(dp[x], dp[y]);
			update(1, 1, n + 1, 1, dp[x]);
		}
		else{
			ll tmp = get(1, 1, n + 1, x, y - 1);
			dp[y] = min(dp[y], tmp + w);
		}
		update(1, 1, n + 1, y, dp[y]);
	}
	// for(int i=1;i<=n+1;i++) cout << dp[i] << ' '; cout << nl;
	cout << dp[n + 1];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}