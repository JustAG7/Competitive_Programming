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
// const int N = 2e5 + 5;
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

const int N = 505;
/*
   0-N
3-W  2-E
   1-S
*/
const int X_DIR[] {-1,+1, 0, 0};
const int Y_DIR[] { 0, 0,+1,-1};
const string DIR = "NSEW";
using pii = pair<int,int>;
const pii INIT(-1,-1);
pii nxt[N][N][4];
int num_rows, num_cols;
char board[N][N];

int ref(int inc, char mirror) {
	if (mirror == '/') 
		return (inc < 2 ? inc + 2 : inc - 2);
	return 3 - inc;
}

int vis_time;
int vis[N][N][4], got[N][N];
int visit(int r, int c, int inc) {
	if (r < 1 or c < 1 or r > num_rows or c > num_cols) return 0;
	if (vis[r][c][inc] >= vis_time) return 0;
	// cerr << "\t@" << vis_time << ' ' << r << ',' << c << ',' << inc << '\n'; 
	// assert((board[r][c] != '.'));
	int count_mirrors = (got[r][c] < vis_time);
	vis[r][c][inc] = vis_time;
	got[r][c] = vis_time;
	int dir = ref(inc, board[r][c]);
	auto [nr, nc] = nxt[r][c][dir];
	return count_mirrors += visit(nr, nc, dir);
}

bool LOCAL_TEST = 0;

void solve(int test_id) {
//	cout << "Case #" << test_id << ": " << endl;
	// LOCAL_TEST = 1;
	if (LOCAL_TEST) {
		num_rows = 200;
		num_cols = 200;
		for (int r = 1; r <= num_rows; r++) {
			for (int c = 1; c <= num_cols; c++) {
				int t = random(1,2);
				board[r][c] = (t == 0 ? '.' : (t == 1 ? '/' : '\\'));
			}
		}
	}
	else {
		cin >> ::num_rows >> ::num_cols;
		for (int r = 1; r <= num_rows; r++) {
			for (int c = 1; c <= num_cols; c++) cin >> board[r][c];
		}
	}
	// DBG(num_rows)
	// DBGn(num_cols)
	for (int d : {0,3, 1,2}) {
		bool ASC = (d == 0 or d == 3);
		int sta_row = 0, fin_row = num_rows + 1;
		int sta_col = 0, fin_col = num_cols + 1;
		int step = +1;
		if (!ASC) {
			step = -1;
			swap(sta_row, fin_row);
			swap(sta_col, fin_col);
		}
		// DBG(sta_row) DBG(fin_row) DBG(sta_col) DBGn(fin_col)
		for (int r = sta_row; r != fin_row + step; r += step) {
			for (int c = sta_col; c != fin_col + step; c += step) {
				int pr = r + X_DIR[d], pc = c + Y_DIR[d];
				if (pr < 1 or pc < 1 or pr > num_rows or pc > num_cols) {
					nxt[r][c][d] = INIT;
					// continue;
				} else {
					nxt[r][c][d] = nxt[pr][pc][d];
					if (board[pr][pc] != '.') 
						nxt[r][c][d] = make_pair(pr, pc);
				}
				// cerr << "nxt(" << r << ',' << c << ',' << DIR[d] << ") = " 
				// 	<< nxt[r][c][d].first << ',' << nxt[r][c][d].second << '\n';
			}
		}
	}
	vis_time = 0;
	int num_mirror = 0;
	for (int r = 1; r <= num_rows; r++)
		for (int c = 1; c <= num_cols; c++)
			num_mirror += (board[r][c] != '.');
	vector<string> ans;
	for (int c = 1; c <= num_cols; c++) {
		for (char putd : {'N', 'S'}) {
			int dir = (putd == 'N') ? 1 : 0;
			int pos = (dir == 1) ? 0 : num_rows + 1;
			auto first = nxt[pos][c][dir];
			if (first != INIT) {
				++vis_time;
				// cerr << putd << c << ' ' << first.first << ' ' << first.second << '\n';
				// DBG(pos) DBG(c) cerr << DIR[dir] << '\n';
				if (visit(first.first, first.second, dir) == num_mirror)
					ans.push_back(putd + to_string(c));
			}
		}
	}
	for (int r = 1; r <= num_rows; r++) {
		for (char putd : {'E', 'W'}) {
			int dir = (putd == 'E') ? 3 : 2;
			int pos = (putd == 'E') ? num_cols + 1 : 0;
			auto first = nxt[r][pos][dir];
			if (first != INIT) {
				++vis_time;
				// cerr << putd << c << ' ' << first.first << ' ' << first.second << '\n';
				// DBG(pos) DBG(r) cerr << DIR[dir] << '\n';
				if (visit(first.first, first.second, dir) == num_mirror)
					ans.push_back(putd + to_string(r));
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto s : ans) cout << s << ' ';
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