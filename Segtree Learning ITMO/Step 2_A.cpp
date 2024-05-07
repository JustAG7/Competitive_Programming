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
struct Node {
	ll value, pref, suff, sum;
	Node(ll _value = 0, ll _pref = 0, ll _suff = 0, ll _sum = 0){
		value = _value;
		pref = _pref;
		suff = _suff;
		sum = _sum;
	}
};
Node tree[4 * N];
ll a[N];
int n, q;
Node merge(Node a, Node b){
	Node ans(0, 0, 0);
	ans.sum = a.sum + b.sum;
	ans.pref = max(a.pref, a.sum + b.pref);
	ans.suff = max(b.suff, b.sum + a.suff);
	ans.value = max({a.value, b.value, a.suff + b.pref});
	return ans;
}
void update(int id,int l,int r,int idx, ll val){
	if(idx < l || r < idx) return;
	if(l == r){
		tree[id].value = max(0LL, val);
		tree[id].pref = max(0LL, val);
		tree[id].suff = max(0LL, val);
		tree[id].sum = val;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m,idx,val);
	update(id * 2 + 1, m + 1, r,idx,val);
	tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
}
Node get(int id,int l,int r,int u,int v){
	if(r < u || v < l) return Node(0, 0, 0);
	if(u <= l && r <= v) return tree[id];
	int m = (l + r)/2;
	return merge(get(id * 2, l, m, u, v), get(id * 2 + 1,m + 1, r, u, v));
}
void solve(){
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	Node ans;
	cout << get(1, 1, n, 1, n).value << nl;
	while(q--){
		int i; ll val;
		cin >> i >> val;
		update(1, 1, n, i + 1, val);
		cout << get(1, 1, n, 1, n).value << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}