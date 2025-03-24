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
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

ll ans = 0;
struct DSU {
	int n;
	vector<ll> par, sum;
	void init(int size){
		n = size;
		par.resize(n + 1, 0);
		sum.resize(n + 1, 0);
	}
	int get(int u){
		return u == par[u] ? u : par[u] = get(par[u]);
	}
	bool join(int u,int v){
		u = get(u);
		v = get(v);
		if(u == v) return false;
		par[u] = v;
		sum[v] += sum[u];
		ans = max(ans, sum[v]);
		return true;
	}
};
void solve(int testID){
	int n;
	cin >> n;
	DSU dsu;
	dsu.init(n);
	ans = 0;
	vector<ll> a(n + 1);
	for(int i=1;i<=n;i++) {
		dsu.par[i] = i;
		cin >> a[i];
		dsu.sum[i] = a[i];
		ans = max(ans, a[i]);
	}
	int q;
	cin >> q;
	cout << ans << nl;
	while(q--){
		int i;
		cin >> i;
		dsu.join(i, i + 1);
		cout << ans << nl;
	}
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}