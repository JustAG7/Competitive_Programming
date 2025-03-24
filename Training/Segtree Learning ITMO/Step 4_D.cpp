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
struct node{
	int cnt[41];
	int diff;
	void combine(const node &a, const node &b){
		diff = 0;
		for(int i=1;i<=40;i++){
			cnt[i] = a.cnt[i] + b.cnt[i];
			if(cnt[i]) diff++;
		}
	}
};
node tree[4 * N];
int a[N];
void update(int id,int l,int r,int idx,int val){
	if(idx < l || r < idx) return;
	if(l == r){
		tree[id].cnt[a[l]] = 0;
		tree[id].cnt[val] = 1;
		tree[id].diff = 1;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, idx, val);
	update(id * 2 + 1, m + 1, r, idx, val);
	tree[id].combine(tree[id * 2], tree[id * 2 + 1]);
}

node get(int id,int l,int r,int u, int v){
	if(v < l || r < u) return node();
	if(u <= l && r <= v) return tree[id];
	int m = (l + r)/2;
	node ans;
	ans.combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
	return ans;
}
void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		update(1, 1, n, i, a[i]);
	}
	while(q--){
		int t, x, y;
		cin >> t >> x >> y;
		if(t == 2){
			update(1, 1, n, x, y);
			a[x] = y;
		}
		else{
			node ans = get(1, 1, n, x, y);
			cout << ans.diff << nl;
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