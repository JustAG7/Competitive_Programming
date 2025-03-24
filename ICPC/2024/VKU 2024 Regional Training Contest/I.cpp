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
// #define mp make_pair
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
const int N = 3e5 + 5;
int pre[N], last[N], a[N];
int mp[N];

struct Query
{
	int l, r, v; // how many in range [l,r] <= v. IF NEGATIVE r, then update
	bool operator< (cst(Query) o) const {
		return (v == o.v ? l < o.l : v < o.v);
	}
};

int fenwick[N], range;
void update(int x) { 
	for (; x <= range; x += x&-x) fenwick[x]++;
}
int query(int x) {
	int res = 0;
	for (; x > 0; x &= x-1) res += fenwick[x];
	return res;
}

void solve(int test_id) {
//	cout << "Case #" << test_id << ": " << endl;
	int n, m;
	cin >> n >> m;
	int diff = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<Query> queries;
	for(int i = 1; i <= n; i++) {
		pre[i] = last[a[i]];
		last[a[i]] = i; 
		queries.push_back({pre[i] + 1, i - 1, pre[i]}); // [l,r] <= v
		queries.push_back({-i, -i, pre[i]}); // i <= v
	}
	ll ans = 0;
	range = n;
	sort(all(queries));
	for (auto [l,r,v] : queries) {
		if (l < 0) update(-l);
		else ans += query(r) - query(l-1);
	}
	// DBGn(ans)
	int cnt = 0;
	{
		for (int i = 1; i <= n; i++) mp[a[i]] = 0;
		for (int i = 1; i <= n; i++) {
			if (!mp[a[i]]) ++cnt;
			++mp[a[i]];
		}		
	}
	int ghost = m - cnt;
	// DBGn(cnt)
	// DBGn(ghost)
	ans += 1ll * cnt * (cnt-1) / 2;
	// DBGn(ans)
	ans += 1ll * cnt * ghost;
	cout << ans;
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