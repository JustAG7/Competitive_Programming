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
struct SegTree{
	vector<ll> tree;
	int n;
	void init(int _n) {
		n = _n;
		tree.assign(4 * n + 5, 0LL);
	}

	void build(int id, int l, int r) {
		if(l == r) return;
		int m = (l + r) / 2;
		build(id * 2, l, m);
		build(id * 2 + 1, m + 1, r);
		calc(id);
	}
	void pullUp(int id){
		tree[id] = max(tree[id * 2], tree[id * 2 + 1]);
	}
	void update(int id,int l,int r,int u,int v,int x){
		if(v < l || r < u) return;
		if(u <= l  && r <= v){
			tree[id] = max(tree[id], x);
			return;
		}
		int m = (l + r)/2;
		update(id * 2, l, m, u, v, x);
		update(id * 2 + 1, m + 1, r, u, v, x);
		pullUp(id);
	}
	void update(int l, int r, int x) {
		update(1, 1, n, l, r, x);
	}
	int getPos(int id, int l, int r, int u, int v, int val) {
		if(v < l || r < u) return -1;
		if(tree[id] < val) return -1;
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
	int get(int id, int l, int r, int u, int v) {
		if(v < l || r < u) return 0;
		if(u <= l && r <= v) return tree[id];
		int m = (l + r) / 2;
		return max(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	}
} SegTree;
void solve(int id){
	
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}