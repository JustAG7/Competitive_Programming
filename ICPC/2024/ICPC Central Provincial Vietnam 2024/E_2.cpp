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
const int N = 105;
const ll inf = 1e18;
const ll INF = 0x3f;

int d[16][N][N];
bool vis[16][N][N];
char a[N][N];
int dp[1 << 15][15];
int r, c, n;
map<int, pair<int,int>> mp;
int m = 0;
bool check(int x, int y) {
	return 1 <= x && x <= r && 1 <= y && y <= c;
}
void bfs(int type, int x, int y) {
	vis[type][x][y] = 1;
	queue<pair<int,int>> q;
	d[type][x][y] = 0;
	q.push({x, y});
	while(!q.empty()) {
		auto [u, v] = q.front();q.pop();
		for(int i=0;i<4;i++) {
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx, dy) && !vis[type][dx][dy] && a[dx][dy] != '#') {
				d[type][dx][dy] = d[type][u][v] + 1;
				vis[type][dx][dy] = 1;
				q.push({dx, dy});
			}
		}
	}
}
int getDist(int i, int j) {
	return d[i][mp[j].X][mp[j].Y];
}
void solve(int testID){
	cin >> r >> c >> n;
	for(int i=1;i<=r;i++) {
		for(int j=1;j<=c;j++) {
			cin >> a[i][j];
			if(a[i][j] == 'S') mp[m++] = {i, j};
		}
	}
	mp[n] = {1, 1};
	for(int i = 0; i <= 15; i++) 
		for(int j = 0; j <= 100; j++) 
			for(int k = 0; k <= 100; k++)
				d[i][j][k] = M; 
	for(int i=0;i<=n;i++) {
		auto [x, y] = mp[i];
		bfs(i, x, y);
	}
	memset(dp, M, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) dp[1 << i][i] = 0;
	
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < n; k++) {
				if(dp[i][j] == M || i & (1 << k) || !(i & (1 << j))) continue;
				dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + getDist(j, k));
			}
		}
	}
	int ans = M;
	for(int i = 0; i < n; i++) {
		ans = min(ans, dp[(1 << n) - 1][i] + d[n][mp[i].X][mp[i].Y]);
	}
	cout << (ans != M ? ans : -1);
}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3