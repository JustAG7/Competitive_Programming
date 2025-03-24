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
const int N = 2e5 + 5;
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

void solve(int test_id) {
	string s; cin >> s;
	vector<char> vow, cow;
	int cnt_Y = 0;
	int cnt_Vow = 0;
	int cnt_Cow = 0;
	int cnt_N = 0;
	int cnt_G = 0;
	for(char si : s) {
		if(si == 'U' or si == 'E' or si == 'O' or si == 'A' or si == 'I') {
			cnt_Vow += 1;
		}
		else if(si == 'Y') {
			cnt_Y += 1;
		}
		else if(si == 'N') {
			cnt_N += 1;
		}
		else if(si == 'G') {
			cnt_G += 1;
		}
		else {
			cnt_Cow += 1;
		}
	}
	int cnt_NG = min(cnt_N, cnt_G);
	cnt_N -= cnt_NG;
	cnt_G -= cnt_NG;
	cnt_Cow += cnt_N + cnt_G;

	int cnt_N_used = 0;
	int ans = 0;

	int cnt_waste = 0;
	while(true) {
		int vow_i = 0;
		if(cnt_Vow > 0) {
			vow_i = 1;
			cnt_Vow -= 1;
		}
		else if(cnt_Y > 0) {
			vow_i = 2;
			cnt_Y -= 1;
		}
		else break;
		string cow_1 = "%", cow_2 = "%";
		if(cnt_NG > 0) {
			cow_1 = "NG";
			cnt_NG -= 1;
			cnt_waste += 1;
		}
		else if(cnt_Cow > 0) {
			cow_1 = "N";
			cnt_Cow -= 1;
		}
		else if(cnt_Y > 0) {
			cow_1 = "Y";
			cnt_Y -= 1;
		}
		else if(cnt_waste > 0) {
			cow_1 = "W";
			cnt_waste -= 1;
		}
		else {
			if(cow_1 == "W") cnt_waste += 1;
			break;
		}
		if(cnt_NG > 0) {
			cow_2 = "NG";
			cnt_NG -= 1;
			cnt_waste += 1;
		}
		else if(cnt_Cow > 0) {
			cow_2 = "N";
			cnt_Cow -= 1;
		}
		else if(cnt_Y > 0) {
			cow_2 = "Y";
			cnt_Y -= 1;
		}
		else if(cnt_waste > 0) {
			cow_2 = "W";
			cnt_waste -= 1;
		}
		else {
			if(cow_2 == "W") cnt_waste += 1;
			if(cow_1 == "W") cnt_waste += 1;
			break;
		}

		ans += 3;

	}
	cout << ans + cnt_waste;
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