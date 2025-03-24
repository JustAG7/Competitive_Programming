// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

/*BITWISE*/
#define mask(n) (1LL << (n))
#define testBit(n, bit) ((n) & mask(bit))
#define flipBit(n, bit) ((n) ^ mask(bit))
#define cntBit(n) (__builtin_popcountll(n))

/*SHORTCUTS*/
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define cst(T) const T&
#define rall(v) (v).rbegin(),(v).rend()
#define nl '\n'

template<class A, class B>
	bool umin(A& var, cst(B) val) {
		if (val < var) return var = val, true;
		return false;
	}
template<class A, class B>
	bool umax(A& var, cst(B) val) {
		if (var < val) return var = val, true;
		return false;
	}


/*NUMERICS*/
using ll = long long;
using ld = long double;
typedef long long Int;
typedef long double Real;
//typedef __int128 Big;
//const int MODS[] = {(int) 1e9+7, (int) 1e9+9, 998244353, 2004010501};
const int MOD = 2004010501;
void add(int& x, cst(int) y) {
	if ((x += y) >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}
int prod(cst(int) x, cst(int) y) { return ((Int)x*y) % MOD; }

const Real EPS = 1e-9;
bool equals(cst(Real) x, cst(Real) y) { return abs(x-y) <= EPS; }

/*DEBUGGING*/
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
//Usage
//TimeVar tBegin = timeNow();
//TimeVar tEnd = timeNow();
//Real measurement = duration(tEnd-tBegin);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << endl;

/*CONSTANTS*/
const Int INF = 1e18;
const Real PI = acos(-1);
const int N = 5e3 + 7;
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
string s;
int n;
int lcp[N][N] = {0};

void calc_lcp() {
	for(int i = n; i >= 1; --i) {
		for(int j = n; j > i; --j) {
			lcp[i][j] = 0;
			if (s[i] == s[j]) lcp[i][j] = 1 + lcp[i+1][j+1];
			umin(lcp[i][j], min(n-j+1, j-i));
		}
	}
}

int cache[N][N];
pair<int,int> trace[N][N];
int dp(int l, int r) {
	if (l > r or r > n) return -N;
	if (r == n) return 1;
	int& res = cache[l][r];
	if (res > 0) return res;
	int t = lcp[l][r];
	res = dp(l, r+1);
	trace[l][r] = {l,r+1};
	if (l != r) {
		if (r-l == t) {
			if (umax(res, 1 + dp(r+1, r+t+1)))
				trace[l][r] = {r+1, r+t+1};
		}
		if (s[l+t] < s[r+t]) {
			if (umax(res, 1 + dp(r+1, r+t)))
				trace[l][r] = {r+1, r+t};
			// cerr << "used "; DBG(l) DBG(r) DBGn(t)
		}
	}
	if (l == r && s[l] < s[l+1]) 
		if (umax(res, 1 + dp(l+1, l+1))) trace[l][r] = {l+1, l+1};
	// DBG(l) DBG(r) DBGn(res)
	return res;
}

vector<int> starts;
void trace_string(int l, int r) {
	DBG(l) DBGn(r)
	auto [ol, nr] = trace[l][r];
	if (r == n or l < ol) {
		starts.push_back(l);
	}
	if (r < n) trace_string(ol, nr);
}

void solve(int test_id) {
//	cout << "Case #" << test_id << ": " << endl;
	cin >> s;
	n = s.size();
	s = '#' + s;
	calc_lcp();
	int num = dp(1,1);
	cout << num << '\n';
	trace_string(1,1);
	starts.push_back(n + 1);
	for (auto s : starts) cerr << s << ' '; cerr << '\n';
	for (int i = 1; i <= num; i++) {
		for (int j = starts[i-1]; j < starts[i]; j++) cout << s[j];
		cout << '\n';
	}

}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3