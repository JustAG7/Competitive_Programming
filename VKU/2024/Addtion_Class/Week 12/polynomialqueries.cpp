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
int a[N], b[N];
ll pref[N];
struct Segtree{
	int size;
	vector<ll> st1, lazy, st2;
	void init(int n){
		size = n;
		st1.assign(4 * n + 5, 0LL);
		lazy.assign(4 * n + 5, 0LL);
		st2.assign(4 * n + 5, 0LL);
	}
	void build(int id,int l,int r){
		if(l == r){
			st2[id] = b[l];
			return;
		}
		int m = (l + r)/2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		st2[id] = st2[id * 2] + st2[id * 2 + 1];
	}
	void pushDown(int id){
		st1[id * 2] += lazy[id] * st2[id * 2];
		lazy[id * 2] += lazy[id];

		st1[id * 2 + 1] += lazy[id] * st2[id * 2 + 1];
		lazy[id * 2 + 1] += lazy[id];

		lazy[id] = 0; 
	}
	void pullUp(int id){
		st1[id] = max(st1[id * 2], st1[id * 2 + 1]);
	}
	void inc(int id,int l,int r,int u,int v,ll x){
		if(v < l || r < u) return;
		if(u <= l && r <= v){
			st1[id] += x * st2[id];
			lazy[id] += x;
			return;
		}
		int m = (l + r)/2;
		pushDown(id);
		inc(id * 2, l, m, u, v, x);
		inc(id * 2 + 1, m + 1, r, u, v, x);
		pullUp(id);
	}
	void inc(int l,int r, ll x){
		inc(1, 1, size, l, r, x);
	}
	
	ll get(int id,int l,int r,int u,int v){
		if(v < l || r < u) return 0LL;
		if(u <= l && r <= v) return st1[id];
		int m = (l + r)/2;
		pushDown(id);
		return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	}
	ll get(int l,int r){
		return get(1, 1, size, l, r);
	}
};

void solve(){
	int n, q;
	cin >> n >> q;

	Segtree inc, dec;
	inc.init(n);dec.init(n);
	for(int i=1;i<=n;i++) b[i] = i;
	inc.build(1, 1, n);
	for(int i=1;i<=n;i++) b[i] = 1;
	dec.build(1, 1, n);

	for(int i=1;i<=n;i++){
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
		b[i] = 1;
	}
	while(q--){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1){
			dec.inc(l, r, -1LL * (l - 1));
			inc.inc(l, r, 1);
		}
		else{
			cout << inc.get(l, r) + dec.get(l, r) + pref[r] - pref[l - 1] << nl;
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