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
ll d[16][N][N];
bool vis[16][N][N];
int a[N][N];
ll dp[1 << 15][15];
int r, c, n;
map<int, pair<int,int>> mp;
int m = 0;
bool check(int x, int y) {
	return 1 <= x && x <= r && 1 <= y && y <= c;
}
void dijkstra(int type, int x, int y) {
	vis[type][x][y] = 1;
	priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> q;
	d[type][x][y] = 0;
	q.push({x, y});
	while(!q.empty()) {
		auto [val, u, v] = q.top();q.pop();
		if(d[type][u][v] != val) continue;
		for(int i=0;i<4;i++) {
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx, dy) && !vis[type][dx][dy] && a[dx][dy] != '#') {
				d[type][dx][dy] = d[type][u][v] + a[u][v];
				vis[type][dx][dy] = 1;
				q.push({d[type][dx][dy], dx, dy});
			}
		}
	}
}
void solve(int testID){

}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3