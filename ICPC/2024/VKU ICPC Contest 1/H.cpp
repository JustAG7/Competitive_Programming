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

ll a, b;
string s;
ll nho[20][2][10];

ll trau(int pos, int ok, int m) {
	if(pos >= s.size()) {
		if(m % 9 == 0) return 0;
		return 1;
	}
	ll &res = nho[pos][ok][m];
	if(res != -1) return res;
	res = 0;
	if (ok) {
		for(int i = 0; i <= 8; ++i) {
			res += trau(pos + 1, ok, (m + i) % 9); 
		}
	}
	else {
		for(int i = 0; i <= s[pos] - '0'; ++i) {
			if(i == 9) continue;
			res += trau(pos + 1, i < (s[pos] - '0'), (m + i) % 9);
		}
	}
	return res;
}

void solve(int testID){
	cin >> a >> b;
	a -= 1;
	s = to_string(a);
	memset(nho, -1, sizeof(nho));
	ll dL = trau(0, 0, 0);

	s = to_string(b);
	memset(nho, -1, sizeof(nho));
	ll dR = trau(0, 0, 0);
	cout << dR - dL << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3