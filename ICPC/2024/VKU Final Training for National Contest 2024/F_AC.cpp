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
const int N = 2e5+5;
const int R = 505;
const ll inf = 1e18;
// const ll INF = 0x3f;
const int INF = 1e9;

int nrows, ncols;
char* board[N];
int* pref[N];
int f[R][R], save_min[R]; // last row is (s,t)

int cost(int row, int l, int r) {
	return pref[row][l-1] + (pref[row][ncols] - pref[row][r]) + ((r-l+1) - (pref[row][r] - pref[row][l-1]));
}

void solve(int testID){
	cin >> nrows >> ncols;
	bool is_swap = (nrows < ncols);
	for (int i = 0; i <= max(nrows, ncols); i++) {
		int t = min(nrows, ncols) + 2;
		board[i] = new char[t+1];
		pref[i] = new int[t+1];
		fill(pref[i], pref[i]+1+t, 0);
	}
	for (int i = 1; i <= nrows; i++) {
		for (int j = 1; j <= ncols; j++) {
			if (is_swap) cin >> board[j][i];
			else cin >> board[i][j];
		}
	}
	if (is_swap) swap(nrows, ncols);
	for (int i = 1; i <= nrows; i++) {
		pref[i][0] = 0;
		for (int j = 1; j <= ncols; j++)
			pref[i][j] = pref[i][j-1] + (board[i][j] == '1');
	}
	for (int i = 0; i <= ncols; i++) {
		for (int j = 0; j <= ncols; j++) f[i][j] = INF;
	}
	// for first row
	for (int j = 1; j <= ncols; j++) {
		f[1][j] = cost(1, 1,j);
		// cerr << f[1][j] << ' ';
	}
	// cerr << '\n';
	for (int r = 2; r <= nrows; r++) {
		// DBGn(r)
		for (int i = 1; i <= ncols; i++)
			for (int j = 1; j <= ncols; j++) umin(f[i][j], f[i-1][j]);
		for (int i = 1; i <= ncols; i++)
			save_min[i] = f[i][i-1];
		for (int i = 1; i <= ncols; i++) {
			// DBGn(i)
			int min_seq = save_min[i];
			for (int j = i; j <= ncols; j++) {
				umin(min_seq, f[i][j]);
				// DBG(j)
				// cerr << "(" << cost(r,i,j) << ',';
				f[i][j] = min_seq + cost(r, i, j);	
				// cerr << f[i][j] << ") ";
			}
			for (int j = 1; j < i; j++) f[i][j] = INF;
			// cerr << '\n';
		}
	}
	int ans = INF;
	for (int i = 1; i <= ncols; i++)
		umin(ans, f[i][ncols]);
	cout << ans;
}

int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3