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

const int MASK = 59049;
Int dp[MASK];

void solve(int testID){
	int n; cin >> n;
	fill(dp, dp+MASK, 0);
	while (n --> 0) {
		Int x; cin >> x;
		// DBGn(x)
		vector<int> d(10,0), c(10);
		for (Int y = x; y > 0; y /= 10) d[y%10]++;

		for (int msk = MASK-1; msk > 0; msk--) {
			{
				for (int i = 0, tmp = msk; i < 10; i++)
					c[i] = tmp % 3, tmp /= 3;
			}
			bool pre = 1; int sub = 0;
			for (int i = 9; i >= 0; i--) {
				c[i] -= d[i];
				if (c[i] < 0) {
					pre = 0;
					break;
				}
				(sub *= 3) += c[i];
			}
			if (pre && sub < msk) 
				if (umax(dp[msk], dp[sub] + x)) ;
					// if (testID == 3)
					// 	cerr << "\t" << msk << ": " << dp[msk] << '\n';
		}
	}
	cout << *max_element(dp, dp+MASK) << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}