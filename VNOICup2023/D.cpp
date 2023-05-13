#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
    this code is from letangphuquy
    thank you a lot
*/
#include<bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
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

template<typename T> vector<T> readInput(int n) {
    vector<T> v(n); for (auto &vi : v) cin >> vi; return v;
}

/*
cbadb
abdbc
obs.1: không có đoạn overlap vì ta luôn có thể merge lại để có chi phí tháo bé hơn

2 đoạn con đồng vị
số chữ cái = nhau

s_ca[r] - s_ca[l] = t_ca[r] - t_ca[l]

s_ca[r] - t_ca[r] = s_ca[l] - t_ca[l]

hash mỗi vị trí = 26 hiệu!!

f[n][k]: cùng k, f đồng biến

--> lấy đoạn xa nhất(!)

g[i] = f[i] - sum[i]
f[i] = min(g[j]) + sum[i]

tham xong merge lại?
*/

const int N = 1e5 + 50;
const int BASE = 200003;
int n, k, a[N];
using Info = array<int,26>;
Info cnt[N]; Int hashVal[N];
Int sum[N];
Int dp[N]; int trace[N];

void solve(int testID) {
    // DBGn(testID);
    string s,t;
    cin >> n >> k;
    cin >> s >> t;
    for (int i = 1; i <= n; i++) cin >> a[i];
    s = "." + s;
    t = "." + t;
    cnt[0].fill(0);
    const int MODS[] {MOD, 998244353};
    const Int INF = 1e18;
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i-1];
        for (int c = 0; c < 26; c++) {
            cnt[i][c] += (s[i] - 'a' == c);
            cnt[i][c] -= (t[i] - 'a' == c);
        }
        // cerr << "at " << i << ": ";
        // for (int c = 0; c < 26; c++)
        //     cerr << cnt[i][c] << ' ';
        // cerr << '\n';
    }
    for (int i = 0; i <= n; i++) {
        hashVal[i] = 0;
        for (int t : {0,1}) {
            int curHash = 0;
            for (int c = 0; c < 26; c++)
                curHash = 1ll * curHash * BASE + (cnt[i][c] + N) % MODS[t];
            hashVal[i] *= 1ll * 1e9;
            hashVal[i] += curHash;
        }
    }
    sum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
    dp[0] = 0;
    map<Int, pair<Int,int>> best;
    for (int i = 1; i <= n; i++) 
        best[hashVal[i]] = {INF, -1};
    best[hashVal[0]] = {sum[0] + dp[0], 0};
    for (int i = 1; i <= n; i++) {
        dp[i] = INF;
        auto [g,j] = best[hashVal[i]];
        if (j != -1) {
            if (umin(dp[i], g + sum[i])) 
                trace[i] = (+1) * j;
        }
        if (s[i] == t[i])
            if (umin(dp[i], dp[i-1]))
                trace[i] = -1;
        if (dp[i] < INF)
            umin(best[hashVal[i]], make_pair(dp[i] - sum[i], i));
    }
    vector<pair<int,int>> segments;
    Int ans = dp[n];
    for (int i = n; i > 0; ) {
        int j = trace[i];
        if (j == -1) { --i; continue; }
        segments.push_back({j+1,i});
        i = j;
    }
    sort(all(segments));
    vector<Int> gaps;
    for (int i = 0; i+1 < (int) segments.size(); i++) {
        int l = segments[i].second + 1;
        int r = segments[i+1].first - 1;
        if (l <= r)
            gaps.push_back(sum[r] - sum[l-1]);
    }
    sort(all(gaps));
    for (int i = 0; i < max(0, (int) segments.size() - k); i++)
        ans += gaps[i];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #define task "WF"
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int numTests = 1;
    // cin >> numTests;
    for (int i = 1; i <= numTests; i++) solve(i);
}
