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
const int N = 2e6+5;
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

ll st[4*N];
ll a[N], b[N];
int d = 1;
void build(int id,int l,int r){
	if(l == r){
		st[id] = a[l];
		return;
	}
	int m = (l + r)/2;
	build(id*2, l, m);
	build(id*2 + 1, m + 1, r);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

void update(int id,int l, int r,int u,int v,int val){
	if(r<u || l>v) return;

	if(u <= l && r <= v){
		b[id] += val;
		st[id] += val;
	}
	int m = (l + r)/2;
	update(id*2,l,m,u,v,val);
	update(id*2+1,m+1,r,u,v,val);
	st[id] = st[id * 2] + st[id * 2 + 1];
}

ll query(int id,int l,int r,int u,int v){
	if(v < l || r < u) return 0;

	if(u <= l && r <= v) return st[id];
	int m = (l + r)/2;
	return query(id*2,l,m,u,v) + query(id*2+1,m+1,r,u,v) + b[id];
}
void solve(){
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x;cin >> x;
			x %= n;
			if(d - )
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