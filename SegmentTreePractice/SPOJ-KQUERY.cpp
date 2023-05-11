#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const int maxn=3e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<int> a(maxn);
vector<vector<int>> t(maxn*4);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void build(int id,int l,int r){
	if(l==r){
		t[id].pb(a[l]);
		return;
	}
	int m=(l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id].resize(t[id*2].size()+t[id*2+1].size());
	merge(all(t[id*2]),all(t[id*2+1]),t[id].begin());
}
int get(int id,int l,int r,int u,int v,int k){
	if (v < l || r < u) return 0;
	if(u<=l && r<=v) return t[id].size()-(upper_bound(all(t[id]),k) - t[id].begin());
	int m=(l+r)/2;
	return get(id*2, l, m, u, v, k) + get(id*2+1, m+1, r, u, v, k);
}
int main(){
	fast;
	indef();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int tt;
	cin >> tt;
	while(tt--){
		int u,v,k;
		cin >> u >> v >> k;
		cout << get(1,1,n,u,v,k) << nl;
	}
}