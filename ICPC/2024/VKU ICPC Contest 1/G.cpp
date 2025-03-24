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
const int N = 1010;
const ll inf = 1e18;
const ll INF = 0x3f;

Int f[N][N][2];
int qty[2];
using Point = pair<int,int>;
Point coord[2][N];
// (1e3)^2 * n

Int dist(cst(Point) p, cst(Point) q) {
	Int x = p.first - q.first, y = p.second - q.second;
	return x*x + y*y;
}

void solve(int testID)
{
	cin >> qty[0] >> qty[1];
	for (int t : {0,1}) {
		for (int i = 1; i <= qty[t]; i++) {
			int x,y;
			cin >> x >> y;
			coord[t][i] = Point(x,y);
		}
	}
	// coord[0][0] = coord[0][1];
	// coord[0][qty[0] + 1] = coord[0][qty[0]];
	// ++qty[0];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		for (int t : {0,1}) f[i][j][t] = inf;
	f[1][0][0] = 0;
	for (int a = 0; a <= qty[0]; a++) {
		for (int b = 0; b <= qty[1]; b++) {
			for (int turn : {0,1}) {
				if (f[a][b][turn] >= inf) continue;
				// cerr << "f(" << a << ',' << b << ',' << turn << ") : " << f[a][b][turn] << '\n';
				auto cur_point = coord[turn][turn == 0 ? a : b];
				if (a+1 <= qty[0])
					umin(f[a+1][b][0], f[a][b][turn] + dist(cur_point, coord[0][a+1]));
				if (b+1 <= qty[1])
					umin(f[a][b+1][1], f[a][b][turn] + dist(cur_point, coord[1][b+1]));
			}
		}
	}
	cout << f[qty[0]][qty[1]][0];
}

int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3