#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include<bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
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
const int N = 5e5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
	return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << '\n';

void solve(int testID) {
	DBGn(testID);
	Int n, p0, x;
	cin >> n >> p0 >> x;
	vector<Int> d;
	Int S = 0;
	d.push_back(0);
	for(int i = 1; i <= n; ++i){
		Int a1; cin >> a1;
		d.push_back(a1);
		S += a1;
	}
	d.push_back(0);
	const Int INF = 1e18;
	Int res = INF;
	Int re = 0;
	for(int i = 1; i <= n + 1; ++i){
		Int t = (x - p0 - re) / S;
		if (t >= 0) res = min(res, p0+S*t+re);

		// Int L = 0, R = abs((p0 + x) / abs(S) + 5)*2LL, opt = -1;
		// while(L <= R) {
		// 	Int m = (L + R) / 2;
		// 	if(p0 + m*S + re >= x) 
		// 		opt = m, L = m+1;
		// 	else R = m - 1;
		// }
		// if (opt > -1) res = min(res, p0 + S * opt + re);
		re += d[i];
	}
	if (p0 >= x) umin(res, p0);
	cout << (res >= INF ? -1 : res);
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	#define task "WF"
	if (fopen(task".inp", "r")) {
		freopen(task".inp", "r", stdin);
		freopen(task".out", "w", stdout);
	}
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}