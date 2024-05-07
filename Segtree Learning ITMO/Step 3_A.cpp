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

int n;
vector<vector<int>> tree(4 * N);
int a[N];
void build(int id,int l,int r){
	if(l == r){
		tree[id].pb(a[l]);
		return;
	}
	int m = (l + r)/2;

	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	tree[id].resize(tree[id * 2].size() + tree[id * 2 + 1].size());
	merge(all(tree[id * 2]), all(tree[id * 2 + 1]), tree[id].begin());
}
int get(int id,int l, int r, int v, int x){
	if(v < l || l > r) return 0;
	// cerr << l << ' ' << r << nl;
	if(r <= v){
		int cnt = lower_bound(all(tree[id]), x) - tree[id].begin();
		return (int)tree[id].size() - cnt;
	}
	int m = (l + r)/2;
	return get(id * 2, l, m, v, x) + get(id * 2 + 1, m + 1, r, v, x);
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1, 1, n);
	vector<int> ans;
	for(int i=n;i>=1;i--){
		ans.pb(get(1, 1, n, i - 1, a[i]));
	}
	reverse(all(ans));
	for(auto x : ans) cout << x << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}