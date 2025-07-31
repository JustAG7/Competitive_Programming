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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 2e5+5;
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

int a[N];
ll dp[N][2], step[N];
ll res[N];
int n, k;

ll add(ll a, ll b) {
	return ((a + b) % M + M) % M;
}
ll mul(ll a, ll b) {
	a %= M;
	b %= M;
	return (a * b) % M;
}
ll bit[N];
void setPos(int u, ll val) {
	for(; u < N; u += (u & -u)) {
		bit[u] = add(bit[u], val);
	}
}

ll get(int u) {
	ll ans = 0;
	for(; u > 0; u -= (u & (-u))) {
		ans = add(ans, bit[u]);
	}
	return ans;
}

void process() {
	cin >> n >> k;
	dp[0][0] = 1;
	for(int i = 1; i <= N - 5; i++) {
		for(int j = 1; j <= 3; j++) {
			if(i < j) continue;
			dp[i][0] = add(dp[i][0], dp[i - j][0]);
			dp[i][1] = add(dp[i][1], dp[i - j][1]);
		}
		if(i >= 4) 
			dp[i][1] = add(dp[i][1], dp[i - 4][0]);
		
		res[i] = add(dp[i][1], dp[i][0]);
	}

	step[1] = 1;
	setPos(1, 1);
	for(int i = 2; i <= N - 5; i++) {
		int l = max(i - k, 1);
		int r = i - 1;
		ll sum = add(get(r), -get(l - 1));
		step[i] = sum;
		if(i - k <= 0) step[i] = add(step[i], 1);
		setPos(i, step[i]);
	}
}

void solve(int id){
	ll ans = 1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ans = mul(ans, mul(step[a[i]], res[a[i]]));
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}