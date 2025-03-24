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


void solve(int testID){
// cerr << "test " << testID << nl;
	int n;
	cin >> n;
	vector<int> m(4, 0), cnt(4, 0);
	cin >> m[1] >> m[2] >> m[3];
	vector<vector<int>> a(n + 1);
	for(int i=1;i<=3;i++) {
		int k; cin >> k;
		for(int j=0;j<k;j++) {
			int x;cin >> x;
			a[x].pb(i);
			cnt[i]++;
		}
	}

	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(a[i].size() == 1 && m[a[i][0]] > 0) {
			m[a[i][0]]--;
			cnt[a[i][0]]--;
			ans++;
		}
	}
	int d[4][4] = {0};
	for(int i = 1; i <= n; ++i) {
		if(a[i].size() == 2) {
			int a1 = a[i][0];
			int a2 = a[i][1];
			d[min(a1, a2)][max(a1, a2)] += 1;
		}
	}
	for(int i = 1; i <= 3; ++i) {
		for(int j = i + 1; j <= 3; ++j) {
			while(d[i][j] > 0) {
				bool fl = false;
				if(m[i] > 0) {
					d[i][j] -= 1;
					m[i] -= 1;
					fl = true;
					ans += 1;
					continue;
				}
				if(m[j] > 0) {
					d[i][j] -= 1;
					m[j] -= 1;
					fl = true;
					ans += 1;
					continue;
				}
				int z = 6 - i - j;
				if(m[z] > 0) {
					d[i][j] -= 1;
					m[z] -= 1;
					fl = true;
					ans += 1;
					continue;
				}
				if(!fl) break;
			}
		}
	}
	int remain = 0;
	for(int i=1;i<=3;i++) remain += m[i];
	for(int i=1;i<=n;i++) {
		if(a[i].size() == 3) {
			if(remain) {
				ans++;
				remain--;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3