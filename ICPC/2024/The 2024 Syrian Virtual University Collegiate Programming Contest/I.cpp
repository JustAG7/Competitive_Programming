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

const int LG = 30;
// int trim_last(int x, int n) {
// 	cerr << "\t" << x << "[-" << n << ":]\n";
// 	return n <= 0 ? 0 : (x & ((1<<n+1) - 1));
// }
// int trim_first(int x, int n) {
// 	cerr << "\t" << x << " [" << ":-" << n << "]\n";
// 	int t = __builtin_popcount(x);
// 	return (t >= n ? (x >> (t - n)) : 0);
// }
// int sub_mask(int x, int high, int low) {
// 	cerr << "\t" << x << " [" << high << ',' << low << "]\n";
// 	if (high < low) return 0;
// 	return trim_first(trim_last(x, high), high - low + 1);
// }

void solve(int testID){
	// DBGn(testID)
	int n;
	cin >> n;
	Int ans = 0;
	int high = 31 - __builtin_clz(n);
	assert((n >> high & 1));
	// DBGn(high)
	for (int b = 0; b <= high; b++) {
		for (int i = b; i >= 0; i--) if ((i-b) % 2 == 0) {
			if (b < high) {
				int cnt = b - (i < b);
				// cerr << "Low " << i << ',' << b << " -> " << cnt << '\n';
				ans += 1ll << cnt;
				continue;
			}
			if (i == b) {
				ans += (n ^ (1<<b)) + 1;
				// DBGn(ans)
				continue;	
			}
			int pre = (n ^ (1<<b)) >> (i+1), suf = n & ((1<<i) - 1);
			ans += 1ll * pre * (1<<i);
			if (n>>i&1) ans += suf+1;
			// if (b >= high) {
			// 	cerr << "high " << b << ", cur " << i << ": ";
			// 	DBG(pre) DBG(suf) DBGn(ans)
			// }
		}
	}
	cout << ans << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}