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

int n, m, q;
vector<string> s;
vector<vector<int>> cnt;

int calc(int p1, int p2) {
	int l1 = 0, l2 = 0, r1 = 0, r2 = 0;
	int ans = 0;
	for(char ci = 'a'; ci <= 'z'; ++ci) {
		int d1 = cnt[p1][ci-'a'];
		int d2 = cnt[p2][ci-'a'];
		r1 = l1, r2 = l2;
		if(d1 > 0) {
			l1 += 1;
			r1 = l1 + d1 - 1;
		}
		if(d2 > 0) {
			l2 += 1;
			r2 = l2 + d2 - 1;
		}
		if(d1 > 0 && d2 > 0) {
			int L = max(l1, l2);
			int R = min(r1, r2);
			if(L <= R)ans += R - L + 1;
		}
		l1 = r1, l2 = r2;
	}
	return ans;
}

void solve(int testID){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		string si; cin >> si;
		vector<int> cnt_i(26, 0);
		for(char sii : si) {
			cnt_i[sii - 'a'] += 1;
		}
		cnt.push_back(cnt_i);
		s.push_back(si);
		// for(int cni : cnt_i) cerr << cni << " "; cerr << '\n';
	}
	cin >> q;
	for(int qi = 0; qi < q; ++qi) {
		int p1, p2; cin >> p1 >> p2;
		cout << calc(p1 - 1, p2 - 1) << '\n';
	}
}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}