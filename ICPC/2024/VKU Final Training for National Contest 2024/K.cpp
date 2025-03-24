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

ll calc_turn(ll x, ll a, ll b, ll mTurn = 0) {
	ll y1 = (b*x - a*x) / a;
	ll L = 1, R = mTurn;

	while(true) {
		if(L == R) break;
		if(L == R-1) {
			ll y2 = (b*(x+R) - a*(x+R)) / a;
			if(y2 == y1) L = R;
			break;
		}
		ll m = (L + R) / 2;
		ll y2 = (b*(x+m) - a*(x+m)) / a;
		if(y2 == y1) L = m;
		else R = m - 1;
	}
	return (L + y1 - 1) / y1;
}
void solve(ll testID){
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	ll max_turn = int(1e9);
	ll x = n;
	ll cnt = 0;
	while(k > 0) {
		ll y = x * (b-a) / a;
		if(y == 0) break;

		ll kx = ( ((y+1)*a + (b-a-1)) / (b-a) );
		ll nTurn = 0;
		if(kx - x <= y) nTurn = 1;
		else {
			nTurn = (kx - x + y - 1) / y;
		}
		if(nTurn * y > k) {
			nTurn = (k + y-1) / y;
		}
		cnt += nTurn;
		x += nTurn * y;
		k -= nTurn * y;
	}
	if(k > 0) cout << -1 << '\n';
	else {
		cout  << cnt << '\n';
	}
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3