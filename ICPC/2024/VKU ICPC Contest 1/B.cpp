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
const int N = 4e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

#define sz(a) int(a.size())

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2,1);
	static vector<C> rt(2,1);
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		for (int i = k; i < 2*k; i++)
			rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vector<int> rev(n);
	for (int i = 0; i < n; i++) rev[i] = (rev[i/2] | (i&1) << L) / 2;
	for (int i = 0; i < n; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; i += 2*k)
			for (int j = 0; j < k; j++) {
				C z = rt[j+k] * a[i+j+k];
				a[i+j+k] = a[i+j] - z;
				a[i+j] += z;
			}
	}
}


vd conv(cst(vd) a, cst(vd) b) {
	if (a.empty() or b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1<<L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	for (int i = 0; i < sz(b); i++) {
		in[i].imag(b[i]);
	}
	fft(in);
	for (C &x : in) x *= x;
	for (int i = 0; i < n; i++) out[i] = in[-i & (n-1)] - conj(in[i]);
	fft(out);
	for (int i = 0; i < sz(res); i++) 
		res[i] = imag(out[i]) / (4*n);
	return res;
}

// void print(cst(vd) v) {
// 	cerr << "|v| = " << sz(v) << '\n';
// 	for (auto elem : v) cerr << fixed << setprecision(4) << elem << ' ';
// 	cerr << '\n';
// }

void solve(int testID){
	int n, szA, szB;
	cin >> n >> szA >> szB;
	vector<db> a(n+2), b(n+2);
	for (int i = 1; i <= szA; i++) {
		int val; cin >> val;
		++a[val];
	}
	for (int i = 1; i <= szB; i++) {
		int val; cin >> val;
		++b[val];
	}
	// print(a);
	// print(b);
	auto res = conv(a,b);
	// print(res);
	for (int i = 2; i <= 2*n; i++) {
		Int t = round(res[i]);
		cout << t << ' ';
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