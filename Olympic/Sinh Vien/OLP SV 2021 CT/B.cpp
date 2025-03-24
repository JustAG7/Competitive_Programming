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

struct SegTree {
	int n;
	vector<ll> sum, minX;
	void init(int _n) {
		n = _n;
		sum.assign(4 * n + 5, 0);
		minX.assign(4 * n + 5, 0);
	}
	void pullUp(int id) {
		sum[id] = sum[id * 2] + sum[id * 2 + 1];
		minX[id] = min(minX[id * 2], minX[id * 2 + 1]);
	}
	void update(int id, int l, int r, int idx, int val) {
		if(idx < l || r < idx) return;
		if(l == r) {
			sum[id] = val;
			minX[id] = val;
			return;
		}
		int m = (l + r)/2;
		update(id * 2, l, m, idx, val);
		update(id * 2 + 1, m + 1, r, idx, val);
		pullUp(id);
	}
	void update(int idx, int val) {
		update(1, 1, n, idx, val);
	}
	int getPos(int id, int l, int r, int u, int v, int val) {
		if(v < l || r < u) return -1;
		if(minX[id] > val) return -1;
		if(l == r) return l;
		int m = (l + r)/ 2;
		int leftNode = getPos(id * 2, l, m, u, v, val);
		if(leftNode != -1) 
			return leftNode;
		return getPos(id * 2 + 1, m + 1, r, u, v, val);
	}
	int getPos(int l, int r, int val) {
		return getPos(1, 1, n, l, r, val);
	}
	int getMin(int id, int l, int r, int u, int v) {
		if(r < u || v < l) return M;
		if(u <= l && r <= v) return minX[id];
		int m = (l + r) / 2;
		return min(getMin(id * 2, l, m, u, v), getMin(id * 2 + 1, m + 1, r, u, v));
	}
	int getMin(int l, int r) {
		return getMin(1, 1, n, l, r);
	}
	ll get(int id, int l, int r, int u, int v) {
		if(r < u || v < l) return 0;
		if(u <= l && r <= v) return sum[id];
		int m = (l + r) / 2;
		return get(id * 2, l, m, u, v) + get(id * 2 + 1, m + 1, r, u, v);
	}
	ll get(int l, int r) {
		return get(1, 1, n, l, r);
	}
} st;
void solve(int id){
	int d = 0;
	ll n, q;
	cin >> n >> q;
	st.init(n);
	for(int i = 1; i <= n; i++) {
		int x;cin >> x;
		st.update(i, x);
	}
	while(q--) {
		int t;
		cin >> t;
		if(t == 1) {
			int D; cin >> D;
			d = (d + D) % n;
		}
		else if(t == 2) {
			ll s, t, val;
			cin >> s >> t >> val;
			ll l = (s - d - 1 + n * n) % n + 1;
			ll r = (t - d - 1 + n * n) % n + 1;
			int mx, pos;
			if(l <= r) {
				mx = st.getMin(l, r);
				pos = st.getPos(l, r, mx);
			}
			else {
				int mLeft = st.getMin(l, n), mRight = st.getMin(1, r);
				if(mLeft <= mRight) pos = st.getPos(l, n, mLeft);
				else pos = st.getPos(1, r, mRight);
			}
			// cout << l << ' ' << r << nl;
			st.update(pos, val);
		}
		else {
			ll s, t;
			cin >> s >> t;
			ll l = (s - d - 1 + n * n) % n + 1;
			ll r = (t - d - 1 + n * n) % n + 1;
			if(l <= r) cout << st.get(l, r) << nl;
			else cout << st.get(l, n) + st.get(1, r) << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}