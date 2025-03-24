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


const int M = 20071008;
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

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
int n, a[N], cnt[N];
pair<int,int> dp[N];
map<int,int> mp;
struct SegTree {
    vector<pair<int,int>> tree;
    int n;
    void init(int _n) {
        n = _n;
        tree.assign(4 * n + 5, {0, 0});
    }
    pair<int,int> combine(pair<int,int> a, pair<int,int> b) {
        if(a.X > b.X) return a;
        if(a.X == b.X) return {a.X, (a.Y + b.Y) % M};
        return b;
    }
    void calc(int id) {
        tree[id] = combine(tree[id * 2], tree[id * 2 + 1]);
    }
    void update(int id, int l, int r, int index, pair<int,int> val) {
        if(index < l || r < index) return;
        if(l == r) {
            tree[id] = combine(tree[id], val);
            return;
        }
        int m = (l + r)/2;
        update(id * 2, l, m, index, val);
        update(id * 2 + 1, m + 1, r, index, val);
        calc(id);
    }

    pair<int,int> get(int id, int l, int r, int u, int v) {
        if(r < u || v < l || l > r) return {0, 0};
        if(u <= l && r <= v) return tree[id];
        int m = (l + r) / 2;
        return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
    }
    void update(int index, pair<int,int> val) {
        update(1, 1, n, index, val);
    }

    pair<int,int> get(int l, int r) {
        return get(1, 1, n, l, r);
    }
} st;
void solve(int id){
    cin >> n;
    st.init(n);
    set<int> s;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    int it = 0;
    for(auto x : s) {
        mp[x] = ++it;
    }
    int ans = 0, res = 0;
    for(int i = 1; i <= n; i++) {
        int pos = mp[a[i]];
        pair<int,int> tmp = st.get(1, pos - 1);
        dp[i].X = tmp.X + 1;
        if(tmp.Y == 0) dp[i].Y = 1;
        else dp[i].Y = tmp.Y;
        res = max(res, dp[i].X);
        st.update(pos, dp[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(dp[i].X == res) ans += dp[i].Y;
        ans %= M;
    }
    cout << ans;
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    for(int t = 1; t <= tt; t++) solve(t);
}
