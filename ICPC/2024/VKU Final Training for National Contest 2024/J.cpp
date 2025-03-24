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
const int N = 50002;
const ll inf = 1e18;
const ll INF = 0x3f;

int a[N + 5];
int position[10 * N];
void flip(int pos) {
	for(int i = pos; i < N - 2; i++) {
		position[a[i]] = -1;
		a[i]--;
		position[a[i]] = i;
	}
}
void init() {
	for(int i = 1; i <= 10 * N; i++) position[i] = -1;
	a[1] = 0;
	a[N - 1] =  99999; 
	a[N] = 100000;
	for(int i = 2; i <= N - 2; i++) {
		a[i] = a[i - 1] + 2;
		position[a[i]] = i;
	}

	position[0] = 1;
	position[99999] = 50001;
	position[100000] = 50002;
}
void solve(int testID){
	cout << 50002 << endl;
	init();
	int prev = -1;
	bool ok = false;
	while(true) {
		int ask; cin >> ask;
		if(ask == -1) {
			for(int i = 1; i <= N; i++) cout << a[i] << ' ';
			cout << endl;
			return;
		}
		if(ask % 2 == 0) {
			if(prev < ask && !ok) {
				flip(position[ask]);
				cout << -1 << endl;
				ok = true;
			}
			else cout << position[ask] << endl;
		}
		else {
			prev = max(prev, ask);
			cout << position[ask] << endl;
		}
	}
}
int main(){
	// fast;
	// indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3