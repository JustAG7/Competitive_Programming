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
const ll n6 = 166666668;

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
ll n, q;
ll b[N];

ll add(ll a, ll b){
    return (a + b) % M;
}
ll sub(ll a, ll b){
    return ((a - b) % M + M) % M;
}
ll mul(ll a, ll b){
    return (a * b) % M;
}
struct Segtree{
    
    int size;
    vector<pair<ll,ll>> lz;
    vector<ll> st1, st2, t;
    void init(int n){
        size = n;
        t.assign(4 * n + 5, 0LL);
        lz.assign(4 * n + 5, {0, 0});
        st1.assign(4 * n + 5, 0LL);
        st2.assign(4 * n + 5, 0LL);
    }
    void build(int id,int l,int r){
        if(l == r){
            st1[id] = (b[l] * b[l]) % M;
            st2[id] = b[l];
            return;
        }
        int m = (l + r)/2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        st2[id] = add(st2[id * 2], st2[id * 2 + 1]);
        st1[id] = add(st[id * 2], st[id * 2 + 1]);
    }
    void pushDown1(int id){
        for(int i = id * 2; i <= id * 2 + 1; i++){
            t[i] = add(t[i], add(mul(lz[id].X, st1[i]), sub(mul(mul(st2[i], n), mul(lz[id].X, lz[id].X - 1)), mul(mul(2, st2[i]), mul(lz[id].X, lz[id].Y)))));
            lz[i].X = add(lz[i].X, lz[id].X);
            lz[i].Y = add(lz[i].Y, lz[id].Y);
        } 
        lz[id] = {0, 0};
    }
    void pullUp(int id){
        t[id] = add(t[id * 2], t[id * 2 + 1]);
    }
    void inc1(int id,int l,int r,int u,int v, ll k, ll L){
        if(u > v || l > r || v < l || r < u) return;
        if(u <= l && r <= v){
            // k * t^2 - 2 * t * k * (L - 1) + t * n * (k - 1) * k
            t[id] = add(t[i], add(mul(lz[id].X, st1[id]), sub(mul(mul(st2[id], n), mul(lz[id].X - 1, lz[id].X)), mul(mul(2, st2[id]), mul(lz[id].X, lz[id].Y)))));
            lz[id].X = add(lz[id].X, k);
            lz[id].Y = add(lz[id].Y, L - 1);
            return;
        }
        int m = (l + r)/2;
        pushDown1(id);
        inc1(id * 2, l, m, u, v, x);
        inc1(id * 2 + 1, m + 1, r, u, v, x);
        pullUp(id);
    }
    void inc1(int l,int r, ll k, ll L){
        inc1(1, 1, size, l, r, k, L);
    }

    ll get1(int id,int l,int r,int u,int v){
        if(v < l || r < u) return 0LL;
        if(u <= l && r <= v) return t[id];
        int m = (l + r)/2;
        pushDown1(id);
        return get1(id * 2, l, m, u, v) + get1(id * 2 + 1, m + 1, r, u, v);
    }
    ll get1(int l,int r){
        return get1(1, 1, size, l, r);
    }
    void pushDown2(int id){

    }
    void inc2(int id,int l,int r,int u,int v, ll k, ll L){
        if(u > v || l > r || v < l || r < u) return;
        if(u <= l && r <= v){
            // k * (L - 1) ^ 2 - n * k * (k - 1) * (L - 1) + n ^ 2 + (k * (k - 1) * (2 * k - 1) * n6)
            
        }
        int m = (l + r)/2;
        pushDown2(id);
    }
};

void solve(){
	cin >> n >> q;
    Segtree t, l;
    t.init(n); l.init(n);
    for(int i=1;i<=n;i++) b[i] = i;
    t.build(1, 1, n);
    for(int i=1;i<=n;i++) b[i] = 1;
    l.build(1, 1, n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll x, m;
            cin >> x >> m;
            ll cnt = m/n;
            ll remain = m % n;

            if(m % n == 0){
                int l1 = 1, r1 = n;
                // cout << l1 << ' ' << r1 << nl;
            }
            else if(x + remain - 1 > n){
                int l1 = x, r1 = n;
                // cout << l1 << ' ' << r1 << nl;
                int l2 = 1, r2 = remain - (r1 - l1 + 1);
                // cout << l2 << ' ' << r2 << nl;
                int l3 = r2 + 1, r3 = x - 1;
                // cout << l3 << ' ' << r3 << nl;
            }
            else{
                int l1 = x, r1 = x + remain - 1;
                // cout << l1 << ' ' << r1 << nl;
                if(cnt > 0){
                    int l2 = r1 + 1, r2 = n;
                    int l3 = 1, r3 = x - 1;
                    // cout << l2 << ' ' << r2 << nl << l3 << ' ' << r3 << nl;
                    
                }
            }
            cout << nl;
        }
        else{
            int i, j;
            cin >> i >> j;   
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