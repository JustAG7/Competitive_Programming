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


const int M = 998244353;
const int N = 5e5+5;
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

ll fact[N], inv_fact[N];
ll pm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return ans;
}
ll C(ll n, ll k) {
	if(k > n) return 0;
	return fact[n] * (inv_fact[k] * inv_fact[n - k] % M) % M;
}
void process() {
	fact[0] = inv_fact[0] = 1;
	for(int i = 1; i <= N - 5; i++) {
		fact[i] = (fact[i - 1] * i) % M;
		inv_fact[i] = pm(fact[i], M - 2);
	}
}
ll mul(ll a, ll b) {
	return (a * b) % M;
}
void solve(int id){
	vector<ll> c(30);
	int n = 0;
	for(int i = 1; i <= 26; i++) {
		cin >> c[i];
		n += c[i];
	}

	int odd = (n + 1) / 2, even = n / 2;
	vector<ll> dp(n + 5, 0);
	dp[0] = 1;
	for(int i = 1; i <= 26; i++) {
		if(c[i] == 0) continue;
		for(int j = odd; j >= c[i]; j--) {
			dp[j] += dp[j - c[i]];
			dp[j] %= M;
		}
	}

	ll ans = dp[odd];
	if(ans) {
		ans = mul(ans, fact[odd]);
		ans = mul(ans, fact[even]);
		for(int i = 1; i <= 26; i++) {
			if(c[i] == 0) continue;
			ans = mul(ans, inv_fact[c[i]]);
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}