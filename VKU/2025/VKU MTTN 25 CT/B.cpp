#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll int64_t
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
const int N = 3e3+5;
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
ll dp[N][N];
ll pre[N];
ll n, W;
bool chosen[N][N];
struct Items {
	ll v, b, a;
	int index;
};
void process() {
	for(ll i = 1; i < N; i++) {
		pre[i] = i * i;
	}
}
void solve(int id){
	cin >> n >> W;
	vector<vector<Items>> p(W + 10);
	for(int i = 1; i <= n; i++) {
		ll w, v, b, a;
		cin >> w >> v >> b >> a;
		if(w <= W) p[w].pb({v, b, a, i});
	}
	for(int i = 1; i <= W; i++) {
		for(int j = 0; j <= W; j++) {
			dp[i][j] = dp[i - 1][j];
		}
		if(!p[i].size()) continue;
		priority_queue<array<ll, 3>> pq;
		ll val = 0;
		for(int j = 0; j < p[i].size(); j++) pq.push({p[i][j].v - p[i][j].a + p[i][j].b, -1, j});

		for(int j = 1; j <= W / i; j++) {
			auto [value, cnt, index] = pq.top(); pq.pop();
			cnt = -cnt;
			// cout << value << ' ' << i << ' ' << cnt << nl;
			if(value < 0) break;
			val += value;
			if (!chosen[i][j]) chosen[i][j] = true;
			else val -= p[i][j].b;
			ll newVal = p[i][index].v * (cnt + 1) - p[i][index].a * pre[cnt + 1] + p[i][index].b;
			// cout << newVal << nl;
			pq.push({newVal, -(cnt + 1), index});
			for(int k = W; k >= i * j; k--) {
				dp[i][k] = max(dp[i][k], dp[i - 1][k - i * j] + val);
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= W; i++) {
		ans = max(ans, dp[W][i]);
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