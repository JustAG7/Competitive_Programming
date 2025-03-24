#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define int long long
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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[N],b[N],c[N];
int st[4*N];

void build(int id,int l,int r){
	if(l == r){
		st[id] = c[l];
		return;
	}
	int m = (l + r) >> 1;
	build(id << 1,l,m);
	build(id << 1 | 1,m+1,r);
	st[id] = min(st[id << 1],st[id << 1 | 1]);
}
int get(int id,int l,int r,int u,int v){
	if(v < l || r < u) return INT_MAX;
	if(u <= l && r <= v) return st[id];
	int m = (l + r) >> 1;
	return min(get(id << 1,l,m,u,v)
		,get(id << 1 | 1,m+1,r,u,v));
}

void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	rep(i,0,n) cin >> a[i];
	rep(i,0,m) cin >> b[i];
	sort(b,b+m);
	rep(i,0,n){
		int pos = lower_bound(b,b+m,a[i]) - b;
		if(pos == 0) pos = 1;
		if(pos >= m) pos = m - 1;
		if(m == 1) c[i + 1] = abs(a[i] - b[m - 1]);		
		else c[i + 1] = min(abs(a[i] - b[pos]),abs(a[i] - b[pos - 1]));
	}
	build(1,1,n);
	while(q--){
		int u,v;
		cin >> u >> v;
		cout << get(1,1,n,u,v) << nl;
	}
}
signed main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
