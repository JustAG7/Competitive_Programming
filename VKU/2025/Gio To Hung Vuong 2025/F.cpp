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

ll pm(ll a, ll b) {
	if(b < 0) return 0;
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return ans;
}
ll add(ll a, ll b) {
	return ((a + b) % M + M) % M;
}
ll mul(ll a, ll b) {
	b %= M;
	return (a * b) % M;
}
ll calc(ll l, ll r) {
	return pm(2, r - 1) - pm(2, l - 1);
}
void solve(int id){
	ll ans = 1;
	int n;
	cin >> n;
	ll l = 1, r = n;

	for(int i = 0; i < n; i++) {
		ll x, y; cin >> x >> y;
		r = l + x - 1;
		cout << l << ' ' << r << nl;
		ans = mul(ans, mul(l, pm(2, r - l)));
		cout << mul(l, pm(2, r - l)) << nl;
		l = r - y + 1;
		cout << l << ' ' << r << nl;

		ans = mul(ans, mul(l, pm(2, r - l)));
		cout << mul(l, pm(2, r - l)) << nl;

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