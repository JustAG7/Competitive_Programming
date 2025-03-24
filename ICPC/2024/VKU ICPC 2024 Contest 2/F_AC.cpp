#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
const int M = 1e9+7;

int nrows, ncols;
const int N = 55;
struct State {
	int y,x, v,u; int corner;
};
bool point_inside(int x, int y, State r) {
	return (r.y <= y && y <= r.v) && (r.x <= x && x <= r.u);
}
struct DP {
	int vis_turn = 0;
	int mark[N][N][N][N][4];
	State trace[N][N][N][N][4];
	DP() {
		memset(mark, 0, sizeof(mark));
		vis_turn = 0;
	}
	/*
	(y,x) to (v,u)
	0 1
	2 3
	*/
	void step(void) { ++vis_turn; }
	bool dfs(int y, int x, int v, int u, int c) {
		if (min({y,x}) < 0) return 0;
		if (v > nrows or u > ncols) return 0;
		auto& vis = mark[x][y][u][v][c];
		if (vis >= vis_turn) return 0;
		// cerr << "(" << y << ',' << x << "); (" << v << ',' << u << "); "<< c << '\n'; 
		vis = vis_turn;
		State cur({y,x,v,u,c});
		auto assign_ = [&] (int ny, int nx, int nv, int nu, int nc) {
			if (dfs(ny, nx, nv, nu, nc))
				trace[ny][nx][nv][nu][nc] = cur;
		};
		// bool root = (x == u && y == v);
		if (c == 0 or c == 1) assign_(y-1, x, v, u, c ^ 1);
		if (c == 2 or c == 3) assign_(y, x, v+1, u, c ^ 1);
		if (c == 0 or c == 2) assign_(y, x-1, v, u, (2-c));
		if (c == 1 or c == 3) assign_(y, x, v, u+1, (4-c));
		return 1;
	}

	string path;
	void trace_path(int y, int x, int v, int u, int c) {
		if (y == v and x == u) return ;
		auto [ny, nx, nv, nu, nc] = trace[y][x][v][u][c];
		if (ny < y) {
			path += "U";
			int t = u-x;
			if (c & 1) while (t--) path += 'R';
			else while (t--) path += 'L';
		} else
		if (nv > v) {
			path += "D";
			if (c & 1) while (t--) path += 'R';
			else while (t--) path += 'L';
		}
		trace_path(ny, nx, nv, nu, nc);

	}
	string get_path(int y, int x, int v, int u, int c) {
		path.clear();
		auto vis = mark[x][y][u][v][c];
		if (vis >= vis_turn) {
			// cerr << "OK\n";
			trace_path(y, x, v, u, c);
		}
		return path;
	}
	string get_path(State s) {
		auto [y, x, v, u, c] = s;
		return get_path(y, x, v, u, c);
	}
} from_start, from_end;

int REV_MAP[256];

string reverse_path(string pt) {
	string res = "";
	reverse(all(pt));
	for (auto a : pt)
		res += (char) REV_MAP[a];
	return res;
}

void solve(int test_id) {
	REV_MAP['L'] = 'R';
	REV_MAP['R'] = 'L';
	REV_MAP['U'] = 'D';
	REV_MAP['D'] = 'U';
	// DBGn()
	cin >> nrows >> ncols;
	from_start.step();
	from_end.step();
	int ys, xs, yt, xt;
	cin >> ys >> xs >> yt >> xt;
	for (int d = 0; d < 4; d++) {
		from_start.dfs(ys, xs, ys, xs, d);
		from_end.dfs(yt, xt, yt, xt, d);
	}
	// vertical
	for (int v = 1; v <= ncols; v++) {
		for (auto c : {1,3}) {
			State rect_left({1, 1, nrows,v, c});
			State rect_right({1, v+1, nrows,ncols, c^1});
			for (int _ : {0,1}) {
				if (point_inside(xs, ys, rect_left) && point_inside(xt, yt, rect_right)) {
					string a = from_start.get_path(rect_left);
					string b = from_end.get_path(rect_right);
					if (a.size() != 0 && b.size() != 0) {
						cout << "YES\n";
						cout << a + reverse_path(b) << '\n';
						return ;
					}
				}
				swap(rect_left, rect_right);
			}
		}
	}
	// horizontal
	for (int v = 1; v <= nrows; v++) {
		for (auto c : {0,1}) {
			State rect_up({1, 1, v,ncols, c});
			State rect_down({v+1, 1, nrows,ncols, c + 2});
			for (int _ : {0,1}) {
				if (point_inside(xs, ys, rect_up) && point_inside(xt, yt, rect_down)) {
					string a = from_start.get_path(rect_up);
					string b = from_end.get_path(rect_down);
					if (a.size() != 0 && b.size() != 0) {
						cout << "YES\n";
						cout << a + reverse_path(b) << '\n';
						return ;
					}
				}
				swap(rect_up, rect_down);
			}
		}
	}
	cout << "NO\n";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3