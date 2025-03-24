#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define mask(n) (1LL << (n))
#define testBit(n, bit) (((n) >> (bit)) & 1)
#define flipBit(n, bit) ((n) ^ (mask(bit)))
#define cntBit(n) __builtin_popcountll(n)

#define pll pair<ll, int>

const int N = 2e5 + 5, MOD = 1e9 + 7;

ll power(ll a, ll n, ll M) {
    if(!n) return 1;
    if(n == 1) return a;
    ll t = power(a, n / 2, M) % M;
    t *= t, t %= M;
    if(n % 2) t *= a, t %= M;
    return t;
}

ll n, m;
ll a[N];

void run_case() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    for(int i = 1; i <= n; i++) if(a[i] == 1) {
        for(int e = 1; e <= n; e++) cout << a[e] << " ";
        return;
    } else pq.push(make_pair(a[i], i));

    for(int e = 1; e <= 1000000; e++) {
        pll it = pq.top(); pq.pop();
        ll smallest = it.first;
        int id = it.second;
        
        if(smallest * smallest < MOD) {
            smallest *= smallest;
            m--;
            a[it.second] = smallest;
            pq.push(make_pair(smallest, id));
        } else break;

        if(!m) break;
    }

    sort(a + 1, a + n + 1);

    if(m > 0) {
        ll cntTurn = m / n, cntRemainder = m % n;
        for(int i = 1; i <= n; i++) {
            a[i] = power(a[i], power(2, cntTurn, MOD - 1), MOD); a[i] %= MOD;
            if(i <= cntRemainder) a[i] *= a[i], a[i] %= MOD;
        }
    }

    for(int i = 1; i <= n; i++) cout << a[i] % MOD << " ";
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(fopen("wf.inp", "r")) {
        freopen("wf.inp", "r", stdin);
        freopen("wf.out", "w", stdout);
    }

    int t = 1;
    // cin >> t;
    while(t--) run_case();
}