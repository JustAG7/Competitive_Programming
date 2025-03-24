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
const int N = 5e3 + 10;
const ll inf = 1e18;
const ll INF = 0x3f;

int num_nodes;
vector<int> adj[N];
string letter;
const string OPEN = "([{";
const string CLOSE = ")]}";
int close_id(char c) { 
	for (int i : {0,1,2}) if (c == CLOSE[i]) return i;
	return -1;
}
int open_id(char c) { 
	for (int i : {0,1,2}) if (c == OPEN[i]) return i;
	return -1;
}

stack<int> sequence; // op: +i was push i, -i was pop i
int brac_id[N];
bool is_open[N];

int answer = 0;
void dfs(int u, int pa) {
	int oper;
	if (!is_open[u]) {
		if (!sequence.size()) return ;
		int top = sequence.top();
		if (brac_id[top] != brac_id[u]) return ; 
		oper = -top;
		sequence.pop();
	} else {
		sequence.push(u);
		oper = u;
	}
	if (sequence.empty()) answer++;
	for (auto v : adj[u]) if (v != pa)
		dfs(v, u);
	// Rollback to parent
	if (oper > 0) sequence.pop();
	else sequence.push((-1) * oper);
}

void solve(int testID) {
	cin >> num_nodes;
	cin >> letter;
	letter = "." + letter;
	for (int u,v, i = 1; i < num_nodes; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= num_nodes; i++) {
		brac_id[i] = open_id(letter[i]);
		is_open[i] = true;
		if (brac_id[i] == -1) {
			brac_id[i] = close_id(letter[i]);
			is_open[i] = false;
		} 
	}
	for (int u = 1; u <= num_nodes; u++) {
		assert(sequence.empty());
		dfs(u,u);
	}
	cout << answer;
}

int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3