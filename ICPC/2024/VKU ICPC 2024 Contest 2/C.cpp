#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
const int M = 1e9+7;

const int second_cases[] {1,2,4,7,10,20,23,26,50,53,270,273,276,282,285,288,316,334,337,340,346,359,362,365,386,389,392,566,630,633,636,639,673,676,682,685,923,926,929,932,1222};

const int N = 1e6 + 5;
int dp[N];
bool mark_grundy[N];

void process() {
	fill(dp, dp+N, 1);
	for (int x : second_cases) dp[x] = 0;

	return ;
	dp[1] = dp[2] = 0;
	for(int i = 3; i < N;i++) {
		fill(mark_grundy, mark_grundy + 1 + i, 0);
		for(int a = 1, b = i-1; a < b; a++, b--) {
			mark_grundy[dp[a] ^ dp[b]] = true;
		}
		for (int g = 0; g <= i; g++) // MEX of next state
			if (!mark_grundy[g]) { dp[i] = g; break; }
	}
}

void solve(int test_id) {
//	cout << "Case #" << test_id << ": ";
	int n; cin >> n;
	cout << (dp[n] ? "first\n" : "second\n");
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	process();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3