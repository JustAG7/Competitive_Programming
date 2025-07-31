// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

#define pb  push_back
#define ff  first
#define ss  second

typedef long long ll;

const int N = 400010;

int bit[N];

void update (int i) {
    for (; i < N; i += (i & (-i)))
        bit[i]++;
}

int query (int i) { 
    int ans = 0;
    for (; i; i -= (i & (-i))) 
        ans += bit[i];
    return ans;
}

int main() {
    int n, a, b; 
    cin >> n >> a >> b;

    vector <int> pys;
    for (int i = 0; i < n; ++i) { 
        int x, y; cin >> x >> y;
        pys.pb(y);
    }

    ll ivs = 0;
    for (int i = 0; i < n; ++i) { 
        ivs += query (pys[i]);
        update (pys[i]);
    }

    ll np = 1ll * n * (n-1) / 2;

    if (a == b)  {
        if (np % 2) {
            if (a == 0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else cout << 1 << '\n';
    }
    else {
        int fs_v = ( ivs % 2 ? a : 0 );
        if ( (np - ivs) % 2 ) fs_v ^= b;

        int sc_v = fs_v ^ a ^ b;

        ll n_intervals = np + 1;

        ll ans = 0;
        if ( fs_v == 0 ) ans += (n_intervals + 1) / 2;
        if ( sc_v == 0 ) ans += (n_intervals) / 2;

        cout << ans << '\n';
    }
    
}
