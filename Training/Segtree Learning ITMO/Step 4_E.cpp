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
int tree[4 * N];
int a[N], n, q;
void update(int id,int l,int r,int idx, int val){
	if(idx < l || r < idx) return;
	if(l == r){
		tree[id] = val;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, idx, val);
	update(id * 2 + 1, m + 1, r, idx, val);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
}
int get(int id,int l,int r, int u, int v, int p){
	if(v < l || r < u) return 0;
	if(tree[id] > p) return 0;
	if(l == r){
		tree[id] = M;
		return 1;
	}
	int m = (l + r)/2;
	int x = get(id * 2, l, m, u, v, p);
	int y = get(id * 2 + 1, m + 1, r, u, v, p);
	tree[id] = min(tree[id * 2], tree[id * 2 + 1]);
	return x + y;
}
void solve(){
	for(int i=1;i<4*N;i++) tree[i] = M;
	cin >> n >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i, h;
			cin >> i >> h;
			update(1, 1, n, i + 1, h);
		}
		else{
			int l, r, p;
			cin >> l >> r >> p;
			cout << get(1, 1, n, l + 1, r, p) << nl;
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