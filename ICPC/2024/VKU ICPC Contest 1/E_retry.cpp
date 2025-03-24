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
const ll inf = 1e18;
// const ll INF = 0x3f;
const int INF = 1e9;

const int N = 105;
int nrows, ncols;
int score[N][N];
int dp[N][N][N][N];
bool calc[N][N];

void sssp(int w, int t) {
	if (calc[w][t]) return;
	calc[w][t] = true;
	#define F dp[w][t]
	F[w][t] = 0;
	for (int y = t+1; y <= ncols; y++) {
		F[w][y] = F[w][y-1] + score[w][y];
		// DBG(y) cerr << F[w][y] << ' ';
	}
	for (int x = w+1; x <= nrows; x++) {
		F[x][t] = F[x-1][t] + score[x][t];
		// DBG(x) cerr << F[x][t] << ' ';
	}
	// DBG(w) DBGn(t)
	for (int x = w+1; x <= nrows; x++)
		for (int y = t+1; y <= ncols; y++) {
			F[x][y] = min(F[x-1][y], F[x][y-1]) + score[x][y];
			// DBG(x) DBGn(y) DBGn(F[x][y])
		}
	// for (int x = w; x <= nrows; x++) {
	// 	for (int y = t; y <= ncols; y++)
	// 		cerr << F[x][y] << ' ';
	// 	cerr << '\n';
	// }
	#undef F
}

void solve(int testID)
{
	cin >> ::nrows >> ::ncols;
	Int mem = sizeof(dp);
	DBG(mem) DBGn(mem / 1e6)
	for (int i = 1; i <= nrows; i++) {
		for (int j = 1; j <= ncols; j++) {
			cin >> score[i][j];
			// cerr << score[i][j] << ' ';
		}
		// cerr << '\n';
	}
	memset(calc, 0, sizeof(calc));
	int q; cin >> q;
	while (q --> 0) {
		int x,y, u,v;
		cin >> x >> y >> u >> v;
		sssp(x, y);
		cout << dp[x][y][u][v] << '\n';
	}

}

int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3