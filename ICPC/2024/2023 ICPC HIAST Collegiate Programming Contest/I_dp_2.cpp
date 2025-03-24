#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
// const int MOD = 2004010501;
const int MOD = 1e9 + 7;
void add(int& x, cst(int) y) {
	if ((x += y) >= MOD) x -= MOD;
	else if (x < 0) x += MOD;
}
int product(cst(int) x, cst(int) y) {
	return 1ll*x*y % MOD;
}
 
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

int f0[N], f1[N], p[N];
int partitions[2][N];

int query(int l) { return l < 0 ? 0 : p[l]; }
int query(int l, int r) { 
	int t = p[r]; 
	add(t, -query(l-1)); 
	return t; 
}

void solve(int testID){
	int n0, n1;
	cin >> n0 >> n1;
	int l0,r0, l1,r1;
	cin >> l0 >> r0 >> l1 >> r1;
	fill(f0, f0+1+n0, 0);
	fill(f1, f1+1+n1, 0);
	fill(p, p+1+n0+n1, 0);
	for (int t : {0,1}) 
		for (int i = 0; i <= n0+n1; i++) partitions[t][i] = 0;
	
	f0[0] = f1[0] = 1;

	int kmax = max(n0/l0, n1/l1) + 1;
	// DBGn(kmax)
	p[0] = 1;
	for (int k = 1; k <= kmax; k++) {
		p[0] = f0[0];
		for (int i = 1; i <= n0; i++) {
			p[i] = p[i-1];
			add(p[i], f0[i]);
		}
		for (int i = n0; i >= 0; i--) f0[i] = query(i-r0, i-l0);
		partitions[0][k] = f0[n0];
	}

	for (int k = 1; k <= kmax; k++) {
		p[0] = f1[0];
		for (int i = 1; i <= n1; i++) {
			p[i] = p[i-1];
			add(p[i], f1[i]);
		}
		for (int i = n1; i >= 0; i--) f1[i] = query(i-r1, i-l1);
		partitions[1][k] = f1[n1];
	}

	int ans = 0;
	for (int k = 1; k <= kmax; k++) {
		// if (partitions[0][k])
		// cerr << "divide 0 to " << k << ": " << partitions[0][k] << '\n';
		// cerr << "divide 1 to " << k << ": " << partitions[1][k] << '\n';
	}
	for (int k = 1; k <= kmax; k++) {
		add(ans, product(partitions[0][k], partitions[1][k-1]));
		add(ans, product(partitions[0][k], partitions[1][k+1]));
		int same = product(partitions[0][k], partitions[1][k]);
		add(same, same);
		add(ans, same);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}