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


const int M = 1e9+7;
const int N = 3e5+5;
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

struct Segtree{
    int size;
    vector<int> st, lazy;
    void init(int n){
        size = n;
        st.assign(4 * n + 5, -1);
        lazy.assign(4 * n + 5, -1);
    }
    void pushDown(int id, int l, int r){
        if(lazy[id] != -1){
            st[id] = lazy[id];
            if(l != r){
                lazy[id * 2] = lazy[id];
                lazy[id * 2 + 1] = lazy[id];
            }
            lazy[id] = -1;
        }
    }
    void pullUp(int id,int l,int r){
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    void update(int id,int l,int r,int u,int v,int x){
        pushDown(id, l, r);
        if(v < l || r < u) return;
        if(u <= l && r <= v){
            st[id] = x;
            if(l != r){
                lazy[id * 2] = x;
                lazy[id * 2 + 1] = x;
            }
            return;
        }
        int m = (l + r)/2;
        update(id * 2, l, m, u, v, x);
        update(id * 2 + 1, m + 1, r, u, v, x);
        pullUp(id, l, r);
    }
    int get(int id,int l,int r,int u,int v){
        if(v < l || r < u) return -1;
        pushDown(id, l, r);
        if(u <= l && r <= v) return st[id];
        int m = (l + r)/2;
        int ans = -1;
        ans = max(ans, get(id * 2, l, m, u, v));
        ans = max(ans, get(id * 2 + 1, m + 1, r, u, v));
        return ans;
    }
    void update(int l,int r,int x){
        update(1, 1, size, l, r, x);
    }
    int get(int l, int r){
        return get(1, 1, size, l, r);
    }
} tree;

void solve(){
    int n, q;
    cin >> n >> q;
    tree.init(n);
    for(int i=1;i<=n;i++){
        int x;cin >> x;
        tree.update(i, i, x);
    }
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int l, r, x;
            cin >> l >> r >> x;
            tree.update(l, r, x);
        }
        else{
            int l, r;
            cin >> l >> r;
            cout << tree.get(l, r) << nl;
        }
    }
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
