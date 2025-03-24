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

int n;
string s;

void solve(int testID){
	// DBGn(testID)
	cin >> n >> s;
	vector<int> freq(10);
	for (auto c : s) freq[c-'0']++;
	if (n == 1) {
		cout << "0 0\n";
		return ;
	}
	int first = -1, last = -1;
	for (int d = 9; d >= 0; d--) {
		if (freq[d]) {
			if (first == -1) first = d; 
			else {
				last = d;
				break;
			}
			if (freq[d] >= 2) {
				last = d;
				break;
			}
		}
	}
	// DBG(first) DBGn(last)
	swap(first, last);
	int cnt = 0, sum = 0;
	if (s[0] - '0' == last && s[n-1] - '0' == first) {
		if (first != last) {
			cnt += 1;
			swap(s[0], s[n-1]);
		}
	}
	else {
		if (s[0] - '0' != first) {
			++cnt;
			for (int i = 1; i < n; i++)
				if (s[i] - '0' == first) {
					swap(s[0], s[i]);
					break;
				}
		}
		if (s[n-1] - '0' != last) {
			++cnt;
			for (int i = 1; i < n; i++)
				if (s[i] - '0' == last) {
					swap(s[i], s[n-1]);
					break;
				}
		}	
	}
	for (int i = 0; i+1 < n; i++) sum += 10 * (s[i] - '0') + (s[i+1] - '0');
	cout << cnt << ' ' << sum << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}