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
#define cst(T) const T&
 
template<class A, class B> bool umin(A& var, cst(B) val) {
	return (val < var) ? (var = val, true) : false;
}
template<class A, class B> bool umax(A& var, cst(B) val) {
	return (var < val) ? (var = val, true) : false;
}
 
typedef long long Int;
typedef long double Real;
const int MOD = 2004010501;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << '\n';

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
const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int n, W, H;
vector<int> w, h;
int dp[110][100010];

void solve(int testID){
	cin >> n >> W >> H;
	w.push_back(0);
	h.push_back(0);
	int res = 0;
	int T = 0;
	for(int i = 1; i <= n; ++i) {
		int wi, ci; cin >> wi >> ci;
		w.push_back(wi);
		h.push_back(ci);
		T += ci;
	}
	for(int ex = 1; ex <= n; ++ex) {
		// memset(dp, 0x3f, sizeof(dp));
		for(int j = 0; j <= T; ++j) {
			dp[0][j] = W + 1;
		}
		dp[0][0] = 0;
		int re = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = T; j >= 0; --j) {
				dp[i][j] = dp[i-1][j];
				if(i == ex) continue;
				if(j - h[i] >= 0) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j-h[i]] + w[i]);
				}
				if(dp[i][j] <= W) {
					re = max(re, j);
				}
			}
		}
		if(H >= w[ex]) {
			re += h[ex];
		}
		res = max(res, re);
	}
	cout << res;
}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}