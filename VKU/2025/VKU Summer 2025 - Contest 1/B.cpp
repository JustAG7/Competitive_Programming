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



int c[N], p[N];
int n, m;

struct SegTree{
    vector<int> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.assign(4 * n + 5, 0);
    }
    void update(int id,int l,int r,int idx,int val){
        if(idx < l || r < idx) return;
        if(l == r){
            tree[id] = max(tree[id], val);
            return;
        }
        int m = (l + r)/2;
        update(id * 2, l, m, idx, val);
        update(id * 2 + 1, m + 1, r, idx, val);
        tree[id] = max(tree[id * 2],tree[id * 2 + 1]);
    }

    int get(int id,int l,int r,int u,int v){
        if(v < l || r < u) return -1;
        if(u <= l && r <= v) return tree[id];
        int m = (l + r)/2;
        return max(get(id * 2, l, m, u, v),get(id * 2 + 1, m + 1, r, u, v));
    }
    void update(int i, int val) {
        update(1, 1, n, i, val);
    }
    int get(int l, int r) {
        return get(1, 1, n, l, r);
    }
} ST;

bool check(int x) {
    if(x == 0) {
        for(int i = 2; i <= n; i++) {
            if(c[i] != c[1]) return false;
        }
        return true;
    }
    int k = m - n, cnt = 0;
    for(int i = 2; i <= n; i++) {
    	if(c[i] - c[i - 1] <= x) continue;
        cnt += (c[i] - c[i - 1] - 1) / x;
        if(cnt > k) break;
    }
    return cnt <= k;
}
void solve(int id){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> c[i];
    sort(c + 1, c + 1 + n);
    if(m < n) {
        ST.init(n);
        for(int i = 2; i <= n; i++) {
            p[i] = c[i] - c[i - 1];
            ST.update(i, p[i]);
        }
        int ans = M;
        for(int i = 2, j = m; j <= n; j++, i++) {
            int res = ST.get(i, j);
            ans = min(ans, res);
        }
        cout << ans;
    }
    else if(m > n) {
        int l = 0, r = 1e9, ans = 1e9;
        while(l <= r) {
            int m = (l + r) / 2;
            if(check(m)) {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        cout << ans;
    }

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
