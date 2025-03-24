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

ll a[N], b[N];
int f[N];
int n;
void calc(int type) {
	deque<int> dq;
	dq.pb(0);
	for(int i=1;i<=n;i++) b[0] = 0;
	b[0] = M;
	for(int i=1;i<=n;i++) {
		while(dq.size() && b[dq.back()] <= a[i]) {
			int num = b[dq.back()];dq.pop_back();
			int cur = dq.back();
			b[cur] += num;
		}
		int pos = type == 0 ? i : n - i + 1;
		int ans = type == 0 ? dq.back() : n - dq.back() + 1;
		if(dq.back() != 0) f[pos] = min(f[pos], abs(pos - ans));
		b[i] = a[i];
		dq.push_back(i);
	}
}
void solve(int testID){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		f[i] = M;
	}
	calc(0);
	reverse(a + 1, a + 1 + n);
	calc(1);
	for(int i=1;i<=n;i++) {
		cout << (f[i] == M ? -1 : f[i]) << ' ';
	}
	cout << nl;
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}