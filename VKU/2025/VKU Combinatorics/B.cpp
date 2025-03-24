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
const int N = 1e6;
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

ll fact[N + 5], inv_fact[N + 5];
ll mod, m = 1;
vector<ll> factor;
ll pm(ll a, ll b, ll M) {
    a %= M;
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
vector<int> getRepresentation(int N, int M) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % M);
        N /= M;
    }
    return res;
}
void process() {
    fact[0] = 1;
    inv_fact[0] = pm(fact[0], mod - 2, mod);
    for(int i = 2, p = mod; i  <= mod; i++) {
        if(p % i == 0) {
            factor.pb(i);
            while(p % i == 0) p /= i;
        }
    }
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv_fact[i] = pm(fact[i], mod - 2, mod);
    }
    for(auto x : factor) {
        m *= x;
        cerr << x << ' '; 
    }
}
ll Ckn(ll n, ll k) {
    if(k > n) return 0;
    return fact[n] * (inv_fact[k] % mod * inv_fact[n - k] % mod) % mod;
}

ll lucas(ll n, ll k, ll m) {
    if(k > n) return 0;
    vector<int> res = getRepresentation(n, m);
    vector<int> tmp = getRepresentation(k, m);
    ll ans = 1;
    for (int i = 0; i < tmp.size(); ++i) {
        ans = (ans * Ckn(res[i], tmp[i])) % m;
    }
    return ans;
}
void solve(ll n, ll k) {
    vector<int> res;
    for(auto x : factor) {
        res.pb(lucas(n, k, x));
    }
    for(int i = 0; i < factor.size(); i++) {
        int x = res[i];
        int y = m / factor[i];
        int z = pm(y, factor[i] - 2, factor[i]);
        cout << x << ' ' << y << ' ' << z << nl;
    }
}
int main(){
    fast;
    indef();
    int tt=1;
    cin >> tt >> mod;
    process();
    for(int t = 1; t <= tt; t++) {
        ll n, k; cin >> n >> k;
        solve(n, k);

    }
}
