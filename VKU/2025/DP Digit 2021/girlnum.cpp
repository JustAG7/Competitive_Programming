// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
    #define JA "WF"
    if(fopen(JA ".inp", "r")){
        freopen(JA ".inp","r",stdin);
        freopen(JA ".out","w",stdout);  
    }
}

ll memo[100005][12][3][2][2];
string s;

bool check(string &s) {
    if (s.size() == 1) return true;
    if (s[0] == s[1]) return false;

    bool prev = s[0] < s[1];
    for (int i = 1; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) return false;
        bool cur = s[i] < s[i + 1];
        if (cur == prev) return false;
        prev = cur;
    }
    return true;
}

ll dp(int pos, int prevNum, int prevMark, bool under, bool zero) {
    if (pos == s.size()) {
        return !zero;
    }

    ll &ans = memo[pos][prevNum][prevMark][under][zero];
    if (ans != -1) return ans;

    ans = 0;
    int limit = under ? 9 : s[pos] - '0';

    for (int i = 0; i <= limit; i++) {
        if (zero && i == 0) {
            ans += dp(pos + 1, 10, 2, under || (i < limit), 1); 
        } 
        else if (prevMark == 2) {
            ans += dp(pos + 1, i, 0, under || (i < limit), 0);
            ans += dp(pos + 1, i, 1, under || (i < limit), 0);
        } 
        else if ((prevMark == 0 && i < prevNum) || (prevMark == 1 && i > prevNum)) {
            ans += dp(pos + 1, i, !prevMark, under || (i < limit), 0);
        }

        ans %= M;
    }

    return ans;
}

void solve(int id) {
    ll a, b;
    cin >> a >> b;
    string l, r;
    cin >> l >> r;

    s = r;
    memset(memo, -1, sizeof memo);
    ll ans = dp(0, 10, 2, 0, 1);
    if(b >= 2) ans = (ans - 9 + M) % M;
    else ans = (ans - stoi(r) + M) % M;
    s = l;
    memset(memo, -1, sizeof memo);
    ll res = dp(0, 10, 2, 0, 1);
    if(a >= 2) res = (res - 9 + M) % M;
    else res = (res - stoi(l) + M) % M;

    // cout << ans << ' ' << res << nl;
    cout << ((ans - res + check(l) + M) % M);
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    time__("solve") {
        for(int t = 1; t <= tt; t++) solve(t);
    }
}
