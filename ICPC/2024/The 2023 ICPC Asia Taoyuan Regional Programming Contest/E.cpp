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

struct Rect {
	Int x,y,u,v;
	bool operator< (cst(Rect) o) const {
		return x < o.x;
	}
};
bool intersect_segments(int l, int r, int L, int R) {
	if (l >= R or L >= r) return 0; // allowed to touch
	return 1;
}

const int N = 215;
Int all_x[N], all_y[N];
int mark[N][N];

int down[N][N], lef[N], rig[N]; // stack max area

vector<Int> compress(vector<Int> a, int n = 0) {
	vector<Int> res(all(a));
	sort(all(res));
	res.resize(unique(all(res)) - begin(res));
	return res;
}
int get_index(cst(vector<Int>) vec, Int x) {
	return lower_bound(all(vec), x) - begin(vec);
}

void solve(int test_id) {
//	cout << "Case #" << test_id << ": ";
	int num_rects;  Int min_dist;
	cin >> num_rects >> min_dist;
	vector<Rect> rects;
	for (int i = 0; i < num_rects; i++) {
		Int x,y,u,v;
		cin >> x >> y >> u >> v;
		rects.push_back({x,y,u,v});
	}
	sort(all(rects));
	Int x_min = INF, x_max = -INF, y_min = INF, y_max = -INF;
	for (auto [x,y,u,v] : rects) {
		umin(x_min, x); umax(x_max, u);
		umin(y_min, y); umax(y_max, v);
	}
	vector<bool> relocated(num_rects + 2, false);
	for (int i = 0; i < num_rects; i++) {
		auto [x,y,u,v] = rects[i];
		if (x != x_min) {
			Int x_bound = x_min;
			for (int j = 0; j < num_rects; j++) {
				if (i == j or !relocated[j]) continue;
				if (intersect_segments(y,v, rects[j].y, rects[j].v))
					umax(x_bound, rects[j].u + min_dist);
			}
			Int shift = x_bound - x;
			// DBG(i) DBGn(shift)
			rects[i].x += shift;
			rects[i].u += shift;
		}
		relocated[i] = true;
	}
	// DBGn(test_id)
	// for (auto [x,y,u,v] : rects) 
	// 	cerr << "(" << x << ',' << y << ',' << u << ',' << v << ")\n";
	for (auto [x,y,u,v] : rects) {
		if (x < x_min or u > x_max or y < y_min or v > y_max) {
			cout << "0\n";
			return ;
		}
	}
	Int new_x_max = 0;
	for (auto [x,y,u,v] : rects) umax(new_x_max,u);
	{
		cout << (x_max - new_x_max) * (y_max - y_min) << '\n';
		return ;
	}
	vector<Int> all_x, all_y;
	all_x.push_back(x_min);
	all_x.push_back(x_max);
	all_y.push_back(y_min);
	all_y.push_back(y_max);
	for (auto [x,y,u,v] : rects) {
		all_x.push_back(x);
		all_x.push_back(u);
		all_y.push_back(y);
		all_y.push_back(v);
	}
	all_x = compress(all_x);
	all_y = compress(all_y);
	int num_x = all_x.size(), num_y = all_y.size();
	cerr << "X: "; for (auto x : all_x) cerr << x << ' '; cerr << '\n';
	cerr << "Y: "; for (auto y : all_y) cerr << y << ' '; cerr << '\n';
	for (int i = 0; i <= num_x + 1; i++)
		for (int j = 0; j <= num_y + 1; j++) 
			mark[i][j] = 0;
	for (auto &[x,y,u,v] : rects) {
		x = get_index(all_x, x);
		u = get_index(all_x, u);
		y = get_index(all_y, y);
		v = get_index(all_y, v);
		for (int i = x; i < u; i++) {
			mark[i][y] += 1;
			mark[i][v] -= 1;
		}
	}
	for (int j = 0; j <= num_y; j++) down[num_x][j] = down[num_x + 1][j] = 0;
	Int area = 0;
	for (int i = num_x - 1; i >= 0; i--) {
		for (int j = 0; j < num_y; j++) {
			if (j > 0) mark[i][j] += mark[i][j - 1];
			down[i][j] = (mark[i][j] == 0) ? (1 + down[i+1][j]) : 0;
		}
		stack<int> incr; // nearest smaller
		for (int j = 0; j < num_y; j++) {
			while (incr.size() && down[i][incr.top()] >= down[i][j])
				incr.pop();
			lef[j] = (incr.size() ? incr.top() : -1) + 1;
			incr.push(j);
		}
		while (incr.size()) incr.pop();
		for (int j = num_y - 1; j >= 0; j--) {
			while (incr.size() && down[i][incr.top()] >= down[i][j])
				incr.pop();
			rig[j] = (incr.size() ? incr.top() : num_y) - 1;
			incr.push(j);
		}
		DBGn(i)
		for (int j = 0; j < num_y; j++) {
			if (down[i][j] <= 0) continue;
			Int x_width = all_y[rig[j]] - all_y[lef[j]];
			// Int y_height = all_x[min(i + down[i][j], num_x - 1)] - all_x[i];
			Int y_height = all_x[i + down[i][j] - 1] - all_x[i];
			DBG(j) DBG(down[i][j]) DBG(lef[j]) DBG(rig[j]) DBG(x_width) DBGn(y_height);
			cerr << "X [" << all_x[i] << ',' << all_x[i + down[i][j] - 1] << "]\n";
			cerr << "Y [" << all_y[lef[j]] << ',' << all_y[rig[j]] << "]\n";
			umax(area, x_width * y_height);
		}
	}
	cout << area << '\n';
	for (int i = 0; i < num_x; i++) {
		for (int j = 0; j < num_y; j++) cerr << mark[i][j] << ' ';
		cerr << '\n';
	}
	for (auto [x,y,u,v] : rects) 
		cerr << "(" << x << ',' << y << ',' << u << ',' << v << ")\n";
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
/*
i = 7
j = 0 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 1 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 2 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 3 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 4 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 5 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
j = 6 down[i][j] = 1 lef[j] = 0 rig[j] = 6 x_width = 14 y_height = 0
i = 6
i = 5
i = 4
j = 3 down[i][j] = 1 lef[j] = 3 rig[j] = 6 x_width = 8 y_height = 0
j = 4 down[i][j] = 1 lef[j] = 3 rig[j] = 6 x_width = 8 y_height = 0
j = 5 down[i][j] = 1 lef[j] = 3 rig[j] = 6 x_width = 8 y_height = 0
j = 6 down[i][j] = 1 lef[j] = 3 rig[j] = 6 x_width = 8 y_height = 0
i = 3
j = 6 down[i][j] = 2 lef[j] = 6 rig[j] = 6 x_width = 0 y_height = 4
i = 2
j = 6 down[i][j] = 3 lef[j] = 6 rig[j] = 6 x_width = 0 y_height = 8
i = 1
j = 0 down[i][j] = 1 lef[j] = 0 rig[j] = 0 x_width = 0 y_height = 0
j = 5 down[i][j] = 1 lef[j] = 5 rig[j] = 6 x_width = 2 y_height = 0
j = 6 down[i][j] = 4 lef[j] = 6 rig[j] = 6 x_width = 0 y_height = 10
i = 0
j = 0 down[i][j] = 2 lef[j] = 0 rig[j] = 0 x_width = 0 y_height = 2
j = 5 down[i][j] = 2 lef[j] = 5 rig[j] = 6 x_width = 2 y_height = 2
j = 6 down[i][j] = 5 lef[j] = 6 rig[j] = 6 x_width = 0 y_height = 12
*/