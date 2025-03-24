#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
const int N = 2e5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ll dp[1005][1005];
int a[1005][1005];
ll fact[N + 5], inv_fact[N + 5];
ll pm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
	}
	return ans;
}
void process() {
	fact[0] = 1;
	for(int i = 1; i <= N; i++)  
		fact[i] = (fact[i - 1] * i) % M;
	
	inv_fact[N] = pm(fact[N], M - 2);
	for(int i = N; i >= 1; i--) {
		inv_fact[i - 1] = (inv_fact[i] * i) % M;
	}
} 
ll Ckn(int n, int k) {
	assert(n >= k);
	return (fact[n] * inv_fact[k] % M * inv_fact[n - k] % M) % M;
}
ll path(int i, int j, int x, int y) {
	assert(i <= x && j <= y);
	return Ckn(x - i + y - j, x - i);
}
void add(ll &a, ll b) {
	a += b;
	if(a > b) a -= M;
	if(a < 0) a += M;
}
void solve(int id){
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int,int>> res;
	for(int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		a[x][y] = -1;
		res.pb({x, y});
	}
	sort(all(res));
	dp[0][1] = 1;
	// for(int i = 0; i <= k; i++) {
	// 	ll sum = path(1, 1, a[i].X, a[i].Y);
	// 	// cout << sum << nl;
	// 	for(int j = 0; j < i; j++) {
	// 		if(a[i].Y - a[j].Y >= 0) {
	// 			sum = sum - dp[j] * path(a[j].X, a[j].Y, a[i].X, a[i].Y) % M;
	// 			if(sum < 0) sum += M;
	// 		}
	// 	}
	// 	dp[i] = sum;
	// }
	for(int i = 1; i <= min(n, 1000); i++) {
		for(int j = 1; j <= min(m, 1000); j++) {
			if(a[i][j] == -1) continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
		}
	}
	// if(max(n, m) <= 1000) return cout << dp[n][m], void();

	ll ans = path(1, 1, n, m);
	for(int i = 0; i < k; i++) {
		cout << path(res[i].X, res[i].Y, n, m) << nl;
		ans = ans - dp[res[i].X][res[i].Y] * path(res[i].X, res[i].Y, n, m);
		if(ans < 0) ans += M;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}
