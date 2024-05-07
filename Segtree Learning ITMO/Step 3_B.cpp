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
int a[N], tree[4 * N];
void update(int id,int l,int r,int idx, int val){
	if(idx < l || r < idx) return;
	if(l == r){
		tree[id] = val;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, idx, val);
	update(id * 2 + 1, m + 1, r, idx, val);
	tree[id] = tree[id * 2] + tree[id * 2 + 1];
}
int get(int id,int l,int r,int x){
	if(l == r) return l;
	int m = (l + r)/2;
	if(tree[id * 2 + 1] > x) return get(id * 2 + 1, m + 1, r, x);
	else return get(id * 2, l, m, x - tree[id * 2 + 1]);
}
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		update(1, 1, n, i, 1);
	}
	vector<int> ans;
	for(int i=n;i>=1;i--){
		int val = get(1, 1, n, a[i]);
		update(1, 1, n, val, 0);
		ans.pb(val);
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