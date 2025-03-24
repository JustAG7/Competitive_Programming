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
const int N = 2e6 + 5;
const ll inf = 1e18;
const ll INF = 0x3f;
const int nmax = 2e6 + 7;

int n, q;
vector<int> a;
int cl_p[nmax] = {0};
bool is_not_p[nmax] = {0};
void sieve() {
	is_not_p[0] = 1;
	is_not_p[1] = 1;
	for(int i = 2; i * i < nmax; ++i) {
		if(!is_not_p[i])continue;
		for(int j = i; j < nmax; j += i) {
			is_not_p[j] = 1;
			cl_p[j] = i;
		}
	}
}
void sieve2(){
	for(int i=2;i<=N-5;i++){
		if(cl_p[i]) continue;
		for(int j=i;j<=N-5;j+=i){
			cl_p[j] = i;
		}
	}
}
const int LG = 22;
int tab[LG][N];

void solve(int testID){
	cin >> n >> q;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for(int i = 0; i < n; ++i) {
		int ai; cin >> ai; a.push_back(ai);
		pq.push({-ai, i + 1});
	}
	int tim = 0;
	while(pq.size()) {
		int u = -pq.top().first;
		int id = pq.top().second;
		pq.pop();
		if(u == 1) {
			tab[0][id] = tim;
			continue;
		}
		tim += 1;
		u /= cl_p[u];
		if(u == 1) {
			tab[0][id] = tim;
		}
		else {
			pq.push({-u, id});
		}
	}
	// for (int i = 1; i <= n; i++) cerr << tab[0][i] << ' '; cerr << '\n';
	for (int t = 1; t < LG; t++) {
		for (int i = 1, j = 1<<t, k = j/2+1; j <= n;
				i++, j++, k++)
			tab[t][i] = max(tab[t-1][i], tab[t-1][k]);
	}
	while(q--) {
		int u,v; 
		cin >> u >> v;
		int t = log2(v-u+1);
		int res = max(tab[t][u], tab[t][v - (1<<t) + 1]);
		cout << res << '\n';
	}
}
int main(){
	fast;
	indef();
	sieve2();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}