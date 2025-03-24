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

void solve(int testID){
	int n; cin >> n;
	vector<ll> a;
	a.push_back(0);
	long long s = 0; 
	for(int i = 0; i < n; ++i) {
		int ai; cin >> ai;
		a.push_back(ai);
		s += ai;
	}
	sort(all(a));
	if(n % 2 == 1) {
		ll med = a[(n + 1) / 2];
		ll med2 = a[(n + 1) / 2 - 1];
		ll x = LLONG_MAX;

		ll x1 = med * (n + 1) - s;
		if(x1 >= med) {
			x = min(x, x1);
		} 
		ll x2 = med2 * (n + 1) - s;
		if(x2 <= med2) {
			x = min(x, x2);
		}
		if(s % n == 0) {
			ll x3 = s / n;
			if(x3 > med2 && x3 < med)
				x = min(x, x3);
		}
		cout << x << '\n';
	}
	else {
		ll med = a[(n + 1) / 2];
		ll med2 = a[(n + 1) / 2 + 1];
		ll x = LLONG_MAX;
		ll x1 = med * (n + 1) - s;
		if(x1 <= med) {
			x = min(x, x1);
		} 
		ll x2 = med2 * (n + 1) - s;
		if(x2 >= med2) {
			x = min(x, x2);
		}
		if(s % n == 0) {
			ll x3 = s / n;
			if(x3 > med && x3 < med2)
				x = min(x, x3);
		}
		cout << x << '\n';
	}
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}