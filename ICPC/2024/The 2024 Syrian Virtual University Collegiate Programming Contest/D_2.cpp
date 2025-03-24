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
const int N = 1e6 + 50;
const ll inf = 1e18;
const ll INF = 0x3f;

int n;
string s;
int pos[N];

void solve(int testID){
	cin >> n >> s;
	int last = -1;
	vector<int> cnt_misplaced(10);
	vector<int> freq(10);
	for (auto c : s) freq[c-'0']++;
	int num_relocations = 0;
	for (char c = 0; c <= 9; c++) {
		for (int i = last+1; i <= last + freq[c]; i++) {
			if (s[i]-'0' != c) {
				++cnt_misplaced[s[i] - '0'];
				++num_relocations;
				s[i] = '0' + c;
			}
		}
		int sz = 0;
		for (int i = last + freq[c] + 1; i < n; i++)
			if (s[i]-'0' == c) pos[++sz] = i;

		for (int d = c+1, i = 1; i <= sz; i++) {
			while (cnt_misplaced[d] <= 0) ++d;
			s[pos[i]] = '0' + d;
			// cerr << "\t" << pos[i] << " -> " << d << '\n';
			--cnt_misplaced[d];
		}
		last += freq[c];
	}
	// DBGn(s)
	int sum = 0;
	for (int i = 0; i+1 < n; i++) 
		sum += 10 * (s[i]-'0') + (s[i+1] - '0');
	cout << num_relocations << ' ' << sum << '\n';
}
int main(){
	fast;
	indef();
	int numTests = 1;
	cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}