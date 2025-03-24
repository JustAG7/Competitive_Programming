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

const int N = 305;
int n; Int k;
int a[N];
Int dp[N][N];
Int cost[N][N];

void solve(int testID){
	cin >> ::n >> ::k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+1+n);
	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			cost[l][r] = 0;
			int m = (l + r) / 2;
			for (int k = l; k <= m; k++) 
				cost[l][r] += a[m] - a[k];
			for (int k = r; k > m; k--)
				cost[l][r] += a[k] - a[m];
		}
	}
	const Int INF = 1e18;
	for (int i = 0; i <= n+1; i++)
		for (int j = 0; j <= n+1; j++) dp[i][j] = INF;
	assert(dp[0][0] >= INF);
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		for (int c = 0; c <= i; c++) {
			if (dp[i][c] > INF) continue;
			for (int j = i+1; j <= n; j++) 
				umin(dp[j][c+1], dp[i][c] + cost[i+1][j]);
		}
	}
	for (int c = 1; c <= n; c++)
		if (dp[n][c] <= k) {
			cout << c << '\n';
			break;
		}
}

int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}