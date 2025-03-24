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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
struct SegTree {
	vector<int> tree;
	int n;
	void init(int _n, int val) {
		n = _n;
		tree.assign(4 * n + 5, val);
		build(1, 1, n);
	}
	void calc(int id) {
		tree[id] = tree[id * 2] + tree[id * 2 + 1];
	}
	void build(int id, int l, int r) {
		if(l == r) return;
		int m = (l + r) / 2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		calc(id);
	}
	void update(int id, int l, int r, int index, int val) {
		if(index < l || r < index) return;
		if(l == r) {
			tree[id] = val;
			return;
		}
		int m = (l + r)/2;
		update(id * 2, l, m, index, val);
		update(id * 2 + 1, m + 1, r, index, val);
		calc(id);
	}
	int get2(int id, int l, int r, int val) {
		if(l == r) return l;
		int m = (l + r) / 2;
		if(val <= tree[id * 2]) return get2(id * 2, l, m, val);
		return get2(id * 2 + 1, m + 1, r, val - tree[id * 2 ]);
	}
	int get1(int id, int l, int r, int u, int v) {
		if(r < u || v < l) return 0;
		if(u <= l && r <= v) return tree[id];
		int m = (l + r) / 2;
		return get1(id * 2, l, m, u, v) + get1(id * 2 + 1, m + 1, r, u, v);
	}
	void update(int index, int val) {
		update(1, 1, n, index, val);
	}
	int get2(int val) {
		return get2(1, 1, n, val);
	}
	int get1(int l, int r) {
		return get1(1, 1, n, l, r);
	}
} st;
int ans1[N], ans2[N], a[N], b[N];
void solve(int id){
	int n;
	cin >> n;
	st.init(n, 0);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cin >> b[i];
	for(int i = 1; i <= n; i++) {
		int res = 0;
		if(a[i] < n) res = max(res, st.get1(a[i] + 1, n));
		ans1[a[i]] = res;
		st.update(a[i], 1);
	}
	st.init(n, 1);
	for(int i = 1; i <= n; i++) {
		int res = st.get2(b[i] + 1);
		ans2[res] = i;
		st.update(res, 0);
	}
	for(int i = 1; i <= n; i++) cout << ans1[i] << ' '; cout << nl;
	for(int i = 1; i <= n; i++) cout << ans2[i] << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}