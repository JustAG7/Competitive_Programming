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

long long n;

// bool check_mask(int pre, int mask) {
// 	if(pre == 9) return false;
// 	if(pre > 9 or pre == 0) return true;
// 	bitset<9> bitmask(mask);
// 	for(int i = 0; i < 9; ++i) {
// 		if(bitmask[i] == 1 and (i + pre) == 9) {
// 			// cout << "fail: " << bitmask << " " << pre << '\n';
// 			return false;
// 		}
// 	}
// 	return true;
// }
// int change_mask(int pre, int mask) {
// 	bitset<9> bitmask(mask);
// 	if(pre > 9) return mask;
// 	for(int i = 8; i > 0; --i) {
// 		if(bitmask[i] == 1 and (i + pre) < 9) {
// 			bitmask[(i + pre)] = 1;
// 		}
// 	}
// 	bitmask[pre] = 1;
// 	return bitmask.to_ulong();
// }
// long long nho[60][60][513][60] = {0};
// long long trau(int i, int pre, int mask, int cnt) {
// 	if(i > n) {
// 		if(check_mask(pre, mask)) {
// 			return cnt + (pre > 0);
// 		}
// 		else return 0;
// 	}
// 	long long &res = nho[i][pre][mask][cnt];
// 	if(res != 0) return res;
// 	res = 0;
// 	res = max(res, trau(i + 1, pre + 1, mask, cnt));
// 	if(check_mask(pre + 1, mask)) {
// 		res = max(res, trau(i + 1, 0, change_mask(pre + 1, mask), cnt + 1));
// 	}
// 	return res;
// }

// void test() {
// 	// n = 11;
// 	for(int i = 1; i < 60; ++i) {
// 		n = i;
// 		vector<int> a1;
// 		memset(nho, 0, sizeof(nho));
// 		cerr << trau(1, 0, 0, 0) << ", ";
// 	}
// }

int preAns[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 5, 4, 6, 5, 7, 6, 8, 8, 9, 9, 10, 9, 11, 9, 12, 9, 13, 9, 14, 10, 15, 11, 16, 12, 17, 13, 18, 14, 19, 15, 20, 16, 21, 17, 22, 18, 23, 19, 24, 20, 25, 21, 26, 22, 27, 23, 28, 24, 29, 25};

void solve(int test_id) {
//	cout << "Case #" << test_id << ": ";
	// test();
	cin >> n;
	if(n < 9) {
		cout << n; return;
	}
	if(n % 2 == 0) {
		ll ans = n / 2;
		cout << ans % M; return;
	}
	if(n < 60) {
		ll ans = preAns[n];
		cout << ans;
		return;
	}
	ll ans = (n - 11) / 2 + 1;
	cout << ans % M;

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