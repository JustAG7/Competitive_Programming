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
// const ll inf = 1e18;
// const ll INF = 0x3f;
const int N = 105;
const int K = 15;
const int MASK = 1 << K;

int side;
#define NEST -1
int board[N][N];
Int dist[K][N][N];

int nants;
int px[K+5], py[K+5];

struct State {
	Int weight; int x,y;
	bool operator< (cst(State) rhs) const {
		return weight > rhs.weight;
	};
};

const Int INF = 1e18;
void sssp(int id) {
	priority_queue<State> heap;
	for (int r = 1; r <= side; r++) {
		for (int c = 1; c <= side; c++) {
			dist[id][r][c] = INF;
		}
	}
	dist[id][px[id]][py[id]] = 0;
	heap.push({0, px[id], py[id]});
	while (!heap.empty()) {
		auto [w,x,y] = heap.top(); heap.pop();

		if (dist[id][x][y] != w) continue;
		for (int d = 0; d < 4; d++) {
			int u = x + moveX[d], v = y + moveY[d];
			if (min(u,v) < 1 or max(u,v) > side) continue;
			Int rel = w + (board[u][v] == NEST ? 0 : board[u][v]);
			if (umin(dist[id][u][v], rel)) {
				heap.push({rel,u,v});
			}
		}
	}
}

const int SHIFT = 8;
const int RIGHT = 1<<SHIFT;
const int LEFT = 1 << (K - SHIFT);
Int cost_left[LEFT][N][N], cost_right[RIGHT][N][N], min_cost[MASK];
Int dp[MASK];

void solve(int testID){
	cin >> side;
	nants = 0;
	for (int i = 1; i <= side; i++) {
		string token;
		for (int j = 1; j <= side; j++) {
			cin >> token;
			board[i][j] = (token == "*") ? NEST : stoi(token);
			if (board[i][j] == NEST) {
				px[nants] = i; py[nants] = j;
				++nants;
			}
			// DBG(i) DBG(j) DBGn(board[i][j])
		}
	}
	memset(dist, 0, sizeof(dist));
	for (int i = 0; i < nants; i++) sssp(i);
	// cerr << "Done SSSP\n";
	int FULL = (1 << nants);
	for (int msk = 0; msk < RIGHT; msk++) {
		int first_bit = -1;
		for (int i = 0; i < SHIFT; i++) 
			if (msk >> i & 1) { first_bit = i; break; }
		if (first_bit == -1) continue;
		int pre = msk ^ (1 << first_bit);
		// DBGn(msk)
		for (int i = 1; i <= side; i++) {
			for (int j = 1; j <= side; j++) if (board[i][j] != NEST) {
				cost_right[msk][i][j] = cost_right[pre][i][j] + dist[first_bit][i][j]; 
				// DBG(i) DBG(j) DBGn(cost_right[msk][i][j])
			}
		}
	}
	// cerr << "Done right\n";
	for (int msk = 0; msk < LEFT; msk++) {
		int first_bit = -1;
		for (int i = 0; i < K - SHIFT; i++) 
			if (msk >> i & 1) { first_bit = i; break; }
		if (first_bit == -1) continue;
		int pre = msk ^ (1 << first_bit);
		for (int i = 1; i <= side; i++) {
			for (int j = 1; j <= side; j++) if (board[i][j] != NEST) {
				cost_left[msk][i][j] = cost_left[pre][i][j] 
					+ dist[SHIFT + first_bit][i][j]; // WTF SO TRIS
			}
		}
	}
	// cerr << "Done left\n";
	for (int msk = 1; msk < FULL; msk++) {
		int left = msk >> SHIFT;
		int right = msk ^ (left << SHIFT);
		min_cost[msk] = INF;
		if (__builtin_popcount(msk) <= 1) {
			min_cost[msk] = 0;
		} else {
			for (int i = 1; i <= side; i++) {
				for (int j = 1; j <= side; j++) if (board[i][j] != NEST) {
					// if (cost_left[left][i][j] > 0) 
					// 	cerr << "left(" << left << ',' << i << ',' << j << ") = " << cost_left[i][j] << '\n';
					umin(min_cost[msk], cost_left[left][i][j] + cost_right[right][i][j]);
				}
			}
		}
	}
	for (int msk = 0; msk < FULL; msk++) {
		if (__builtin_popcount(msk) <= 1) {
			dp[msk] = 0;
			continue;
		}
		dp[msk] = INF;
		for (int sub = msk; sub > 0; (sub -= 1) &= msk)
			if (sub < msk) umin(dp[msk], dp[sub] + dp[msk ^ sub]);
		dp[msk] += min_cost[msk];
	}
	cout << dp[FULL - 1];

}
int main(){
	fast;
	indef();
	int numTests = 1;
	// cin >> numTests;
	for (int i = 1; i <= numTests; i++) solve(i);
}
// xquin cute <3