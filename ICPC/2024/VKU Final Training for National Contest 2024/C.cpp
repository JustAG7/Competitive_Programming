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

#define int long long

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
const int N = 3333;
const int R = 505;
const ll inf = 1e18;
// const ll INF = 0x3f;
const int INF = 1e9;

int r,c, rad, n;
int px[N], py[N], vx[N], vy[N];

vector<int> get_coord(int* x, int qty, int lim) {
	vector<int> res;
	res.pb(1);
	res.pb(lim);
	for (int i = 1; i <= qty; i++) {
		res.pb(x[i]);
		if (x[i] > 1) res.pb(x[i] - 1);
		if (x[i]+1 <= lim) res.pb(x[i] + 1);
	}
	sort(all(res));
	res.resize(unique(all(res)) - begin(res));
	int old_size = res.size();
	for (int i = 0; i+1 < old_size; i++) {
		int dif = res[i+1] - res[i];
		if (dif <= 1) continue;
		res.pb(res[i] + dif/2);
		if (dif % 2 != 0) res.pb(res.back() + 1); 
	}
	sort(all(res));
	// res.resize(unique(all(res)) - begin(res));
	return res;
}
int get_index(cst(vector<int>) vec, int x) {
	return lower_bound(all(vec), x) - vec.begin();
}

int pref[N]; bool mark[N];

void solve(int testID){
	cin >> r >> c >> rad >> n;
	for (int i = 1; i <= n; i++) {
		cin >> px[i] >> py[i];
	}
	auto all_x = get_coord(px, n, r);
	auto all_y = get_coord(py, n, c);
	// cerr << "X: "; for (auto x : all_x) cerr << x << ' '; cerr << '\n';
	// cerr << "Y: "; for (auto y : all_y) cerr << y << ' '; cerr << '\n';
	int sz_y = all_y.size();
	for (int i = 1; i <= n; i++) {
		vx[i] = get_index(all_x, px[i]);
		vy[i] = get_index(all_y, py[i]);
	}
	int ans = n;
	for (auto x : all_x) {
		fill(pref, pref + 1 + sz_y, 0);
		fill(mark, mark + 1 + sz_y, 0);

		// DBGn(x)
		for (int i = 1; i <= n; i++) {
			int dx = abs(px[i] - x);
			if (dx > rad) continue;
			if (dx == 0) mark[vy[i]] = 1;
			int y_dif = sqrt(rad  * rad - dx * dx);
			int y_min = py[i] - y_dif, y_max = py[i] + y_dif;
			int lo, hi, pos;
			int pos_min = 0, pos_max = -1;
			{
				lo = 0;
				hi = sz_y - 1;
				pos = N;
				while (lo <= hi) {
					int mid = (lo+hi) / 2;
					if (all_y[mid] >= y_min) pos = mid, hi = mid-1;
					else lo = mid + 1;
				}
				pos_min = pos;
			}
			{
				lo = 0;
				hi = sz_y - 1;
				pos = -N;
				while (lo <= hi) {
					int mid = (lo+hi) / 2;
					if (all_y[mid] <= y_max) pos = mid, lo = mid+1;
					else hi = mid-1;
				}
				pos_max = pos;
			}
			if (pos_min <= pos_max) {
				++pref[pos_min];
				--pref[pos_max + 1];
			}
			// DBG(i) DBG(y_min) DBG(y_max) DBG(pos_min) DBGn(pos_max)
		}
		// cerr << "??"; for (int i = 0; i <= sz_y; i++) cerr << pref[i] << ' '; cerr << '\n';
		// cerr << "COUNT: ";
		for (int i = 0; i < sz_y; i++) {
			if (i > 0) pref[i] += pref[i-1];
			// cerr << pref[i] << ' ';
			if (!mark[i]) umin(ans, pref[i]);
			// umin(ans, pref[i] - (i > 0 ? pref[i-1] : 0));
		}
		// cerr << '\n';
	}
	cout << ans;
}

signed main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3