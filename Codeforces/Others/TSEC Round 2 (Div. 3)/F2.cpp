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


const int M = 1e9+7;
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
ll a[N], pref[N];
struct SegmentTree {
    vector<ll> t;
    int n;

    void init(int _n) {
        n = _n;
        t.assign(4 * n + 5, 0);
        build(1, 1, n);
    }

    void build(int id, int l, int r) {
        if (l == r) {
            t[id] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(id * 2, l, m);
        build(id * 2 + 1, m + 1, r);
        t[id] = t[id * 2] + t[id * 2 + 1];
    }

    void update(int id, int l, int r, int u, ll val) {
        if (u < l || r < u) return;
        if (l == r) {
            t[id] = val;
            return;
        }
        int m = (l + r) / 2;
        update(id * 2, l, m, u, val);
        update(id * 2 + 1, m + 1, r, u, val);
        t[id] = t[id * 2] + t[id * 2 + 1];
    }

    ll get(int id, int l, int r, int u, int v) {
        if (r < u || v < l) return 0;
        if (u <= l && r <= v) return t[id];
        int m = (l + r) / 2;
        return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
    }

    void update(int i, ll val) {
        update(1, 1, n, i, val);
    }

    ll get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};

void solve(int id) {
    int n, q;
    cin >> n >> q;
    SegmentTree st_dcr, st_inc;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    st_dcr.init(n);
    st_inc.init(n);

    for (int i = 1; i <= n; i++) {
        st_dcr.update(i, a[i]);                   
        st_inc.update(i, a[i] * i);     
    }

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i, val;
            cin >> i >> val;
            st_dcr.update(i, val);           
            st_inc.update(i, val * i);  
            a[i] = val;                          
        } else {
            ll l, r;
            cin >> l >> r;
            ll x = st_inc.get(l, r);  
            ll y = st_dcr.get(l, r);              
            cout <<  x - (l - 1) * y << nl;
        }
    }
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}