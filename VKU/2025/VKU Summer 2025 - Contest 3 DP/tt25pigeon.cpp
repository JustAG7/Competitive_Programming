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


const ll M = 1e18 + 9;
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
int n, k;
ll memo[105][105][2][2];
ll dp(int pos, int prev, bool reach1, bool reachN) {
	if(pos == k) {
		return reach1 && reachN;
	}
	ll &res = memo[pos][prev][reach1][reachN];
	if(res != -1) return res;
	
	res = 0;
	if(prev + 1 <= n) res += dp(pos + 1, prev + 1, reach1 || (prev + 1 == 1), reachN || (prev + 1 == n));
	res %= M;
	if(prev - 1 >= 1) res += dp(pos + 1, prev - 1, reach1 || (prev - 1 == 1), reachN || (prev - 1 == n));
	res %= M;

	return res;
}
void solve(int id){
	cin >> n >> k;
	memset(memo, -1, sizeof memo);
	ll ans = 0;
	for(int d = 1; d <= n; d++) {
		ans += dp(1, d, d == 1, d == n);
		ans %= M;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	// time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	// }
}