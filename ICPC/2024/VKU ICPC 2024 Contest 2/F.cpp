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
const int N = 2e5 + 5;

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
const int M = 1e9+7;

int ax[] = {-1, 1, 0, 0};
int ay[] = {0, 0, -1, 1};

#define ii pair<int, int>

int n, m;
ii st, ed;
int trace[57][57] = {0};
void trau(ii pos, int step) {
		cout << "Step: " << step << " Pos: " << pos.fi << " " << pos.se << '\n';
	if(step == n * m) {
		cout << "Pos: " << pos.fi << " " << pos.se << '\n';
		throw "heh";
	}
	if(pos == ed) {
		return;
	}
	for(int i = 0; i < 4; ++i) {
		ii v = pos;
		v.fi += ax[i];
		v.se += ay[i];
		if(v.fi <= 0 or v.fi > n or v.se <= 0 or v.se > m) continue;
		if(trace[v.fi][v.se] != 0) continue;
		trace[v.fi][v.se] = step;
		trau(v, step + 1);
		trace[v.fi][v.se] = 0;
	}
}

void solve(int test_id) {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) trace[i][j] = 0;
	int st_fi, st_se; cin >> st_fi >> st_se; 
	st = {st_fi, st_se};
	cin >> st_fi >> st_se; 
	ed = {st_fi, st_se};
	try {
		trace[st.fi][st.se] = 1;
		trau(st, 2);
		cout << "NO\n";
	} catch(...) {
		cout << "YES\n";
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cout << trace[i][j] << ' ';
			}
			cout << '\n';
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3