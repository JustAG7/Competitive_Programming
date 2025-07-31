// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
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
#define bit(x, i) (((x) >> (i)) & 1LL)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 3e5+5;
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

const int LEN = 61;
string s;
ll n, k;


string getBinary(ll n) {
	string ans = "";
	while(n > 0) {
		if(n % 2 != 0) ans = "1" + ans;
		else ans = "0" + ans;
		n /= 2;
	}
	while(ans.size() < LEN) ans = "0" + ans;
	return ans;
}

ll dp[62][62][62][2];
ll calc(int pos, int cur, int mx, bool under) {
	// cout << pos << ' ' << cur << ' ' << mx << ' ' << under << nl;
	if(pos == LEN) {
		return mx >= k;
	}
	ll &res = dp[pos][cur][mx][under];
	if(res != -1) return res;
	res = 0;
	int limit = under ? 1 : s[pos] - '0';
	// cout << limit << nl;
	for(int i = 0; i <= limit; i++) {
		if(i == 0) res += calc(pos + 1, 0, mx, under | (i < limit));
		else res += calc(pos + 1, cur + 1, max(cur + 1, mx), under | (i < limit));
	}
	return res;
}
ll get(ll n) {
	memset(dp, -1, sizeof dp);
	s = getBinary(n);
	return calc(0, 0, 0, 0);
}
void solve(int id){
	cin >> n >> k;
	ll l = n, r = 3e18, ans = -1;
	ll res = get(n - 1) + 1;
	// cout << res << nl;	
	while(l <= r) {
		ll m = (l + r) / 2;
		if(get(m) >= res) {
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}