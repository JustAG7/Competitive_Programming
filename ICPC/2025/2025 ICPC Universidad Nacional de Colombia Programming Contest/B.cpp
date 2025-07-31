#include<bits/stdc++.h>
using namespace std;

/*BITWISE*/
#define mask(n) (1LL << (n))
#define testBit(n, bit) ((n) & mask(bit))
#define flipBit(n, bit) ((n) ^ mask(bit))
#define cntBit(n) (__builtin_popcountll(n))

/*SHORTCUTS*/
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define cst(T) const T&

template<class A, class B>
    bool umin(A& var, cst(B) val) {
        if (val < var) return var = val, true;
        return false;
    }
template<class A, class B>
    bool umax(A& var, cst(B) val) {
        if (var < val) return var = val, true;
        return false;
    }


/*NUMERICS*/
using ll = long long;
using ld = long double;
typedef long long Int;
typedef long double Real;
//typedef __int128 Big;
//const int MODS[] = {(int) 1e9+7, (int) 1e9+9, 998244353, 2004010501};
const int MOD = 2004010501;
void add(int& x, cst(int) y) {
    if ((x += y) >= MOD) x -= MOD;
    if (x < 0) x += MOD;
}
int prod(cst(int) x, cst(int) y) { return ((Int)x*y) % MOD; }

const Real EPS = 1e-9;
bool equals(cst(Real) x, cst(Real) y) { return abs(x-y) <= EPS; }


/*DEBUGGING*/
typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::nanoseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()
//Usage
//TimeVar tBegin = timeNow();
//TimeVar tEnd = timeNow();
//Real measurement = duration(tEnd-tBegin);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class X, class Y> Int random(const X& l, const Y& r) {
    return uniform_int_distribution<Int>(l,r)(rng);
}
#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << endl;

/*CONSTANTS*/
const Int INF = 1e18;
const Real PI = acos(-1);

const int N = 105;
int nrows, ncols;
int idx[N][N];
pair<int,int> pos[N*N];

#define FREE '.'
#define BALL 'X'
#define WALL '#'

char board[N][N]; //
string final[N]; 
Int final_state;

Int encode(string* state) {
    Int mask = 0;
    for (int i = 1; i <= nrows; i++)
        for (int j = 1; j <= ncols; j++)
            mask |= (1LL * (state[i][j] == BALL)) << idx[i][j];
    return mask;
}

// decode to board
void decode(Int mask) {
    for (int i = 1; i <= nrows; i++) {
        for (int j = 1; j <= ncols; j++) {
            if (board[i][j] == WALL) continue;
            board[i][j] = ((mask >> idx[i][j] & 1) ? BALL : FREE);
        }
    }
}

const int X_DIR[] = {-1,+1, 0, 0};
const int Y_DIR[] = { 0, 0,-1,+1};

map<Int,bool> mark;
bool dfs(Int stt) {
    if (mark[stt]) return 0;
    // DBGn(stt)
    mark[stt] = 1;
    if (stt == final_state) return 1;
    for (int dir : {0,1,2,3}) {
        decode(stt);
        // MOVE THE BALL
        for (int b = 0; b < nrows*ncols; b++) if (stt>>b&1) {
            auto [i,j] = pos[b];
            pair<int,int> last(i,j);
            while (board[i][j] != WALL) {
                i += X_DIR[dir];
                j += Y_DIR[dir];
                if (board[i][j] == FREE) last = {i,j};
            }
            board[pos[b].first][pos[b].second] = FREE;
            board[last.first][last.second] = BALL;
        }
        if (dfs(encode(board))) return 1;
    }
    return false;
}


void solve(int test_id) {
    // cerr << "Case #" << test_id << ": ";
    cin >> nrows >> ncols;
    {
        int c = 0;
        for (int i = 1; i <= nrows; i++)
            for (int j = 1; j <= ncols; j++) {
                pos[c] = {i,j};
                idx[i][j] = c++;
            }
    }

    for (int i = 1; i <= nrows; i++) {
        for (int j = 1; j <= ncols; j++) cin >> board[i][j];
    }
    for (int i : {0,nrows+1})
        for (int j = 0; j <= ncols + 1; j++) board[i][j] = WALL;
    for (int j : {0,ncols+1})
        for (int i = 0; i <= nrows + 1; i++) board[i][j] = WALL;

    for (int i = 1; i <= nrows; i++)
        for (int j = 1; j <= ncols; j++) cin >> final[i][j];
    final_state = encode(final);

    if (dfs(encode(board))) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    if (fopen("WF.inp", "r")) {
        freopen("WF.inp", "r", stdin);
        freopen("WF.out", "w", stdout);
    }
    int numTests = 1;
    // cin >> numTests;
    for (int i = 1; i <= numTests; i++) solve(i);
}
// xq cute <3