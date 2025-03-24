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
const int N = 2e5+5;
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
int n, q, r;
struct mat{
	ll data[2][2];
	mat(ll a = 0,ll b = 0,ll c = 0,ll d = 0){
		data[0][0] = a;
		data[0][1] = b;
		data[1][0] = c;
		data[1][1] = d;
	}
	void print(){
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				cout << data[i][j] << ' ';
			}
			cout << nl;
		}
	}
};

mat tree[4 * N], ar[N];

inline mat mul(mat &a, mat &b){
	mat ans;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				ans.data[i][j] = (ans.data[i][j] + (a.data[i][k] * b.data[k][j] % r)) % r;
			}
		}
	}
	return ans;
}
void build(int id,int l,int r){
	if(l == r){
		tree[id] = ar[l];
		return;
	}
	int m = (l + r)/2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	tree[id] = mul(tree[id * 2], tree[id * 2 + 1]);
}
mat get(int id,int l, int r,int u,int v){
	if(u <= l && r <= v) return tree[id];
	int m = (l + r)/2;
	bool a = true, b = true;
	mat x, y;
	if(!(l > v || m < u)) x = get(id * 2, l, m, u, v);
	else a = false;
	if(!(m + 1 > v || r < u)) y = get(id * 2 + 1, m + 1, r, u, v);
	else b = false;
	if(!a) return y;
	if(!b) return x;
	return mul(x, y);
}
void solve(){
	cin >> r >> n >> q;
	for(int i=1;i<=n;i++){
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		ar[i] = mat(a, b, c, d);
	}
	build(1, 1, n);
	while(q--){
		int l, r;
		cin >> l >> r;
		mat ans = get(1, 1, n, l, r);
		ans.print();
		cout << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}