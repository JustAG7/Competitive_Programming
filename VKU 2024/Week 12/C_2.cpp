#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll int
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
	vector<ll> st, lazySet, lazySum;
	void init(int n){
		size = n;
		st.assign(4 * n + 5, 0LL);
		lazySet.assign(4 * n + 5, 0LL);
		lazySum.assign(4 * n + 5, 0LL);
	}

	void pushDown(int id,int l,int r){
		int m = (l + r)/2;
		if(lazySet[id] != -1){

			lazySet[id * 2 + 1] = lazySet[id];
			lazySet[id * 2] = lazySet[id];

			st[id * 2] = lazySet[id];
			st[id * 2 + 1] = lazySet[id];

			lazySet[id] = -1;
		}

	}

	void pullUp(int id){
		st[id] = max(st[id * 2], st[id * 2 + 1]);
	}
	void set(int id,int l,int r,int u,int v,int x){
		if(v < l || r < u) return;
		if(u <= l && r <= v){
			st[id] = x;
			lazySet[id] = x;
			return;
		}
		int m = (l + r)/2;
		pushDown(id, l, r);
		set(id * 2, l, m, u, v, x);
		set(id * 2 + 1, m + 1, r, u, v, x);
		pullUp(id);
	}	
	void set(int l,int r,int x){
		set(1, 1, size, l, r, x);
	}
	ll get(int id,int l,int r,int u,int v){
		if(v < l || r < u) return 0LL;
		if(u <= l && r <= v) return st[id];
		int m = (l + r)/2;
		pushDown(id, l, r);
		return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	}
	ll get(int l,int r){
		return get(1, 1, size, l, r);
	}
};
void solve(){
	int n, q;
	cin >> n >> q;
	Segtree st;
	st.init(n);
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		st.set(i, i, x);
	}
	while(q--){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 2){
			cout << st.get(l, r) << nl;
		}
		else{
			int x;cin >> x;
			if(t == 1) st.set(l, r, x);
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