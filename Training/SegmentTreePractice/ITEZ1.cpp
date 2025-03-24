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
const ll maxn=1e5+5;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vector<int> t(4*maxn,0);
vector<int> a(maxn,0);
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,   l,   mid);
	build(id*2+1,mid+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int p){
	if(l>p || p>r) return;
	if(l==r){
		t[id]=a[p];
		return;
	}
	int mid=(l+r)/2;
	update(id*2,l,mid,p);
	update(id*2+1,mid+1,r,p);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
	if(r<u || l>v) return -1e9;
	if(u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int main(){
	fast;
	indef();
	int n,tt;
	cin >> n ;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	cin >> tt;
	while(tt--){
		int t,u,v;
		cin >> t >> u >> v;
		if(t==1){
			a[u]=v;
			update(1,1,n,u);
		}
		else if(t==2) cout << get(1,1,n,u,v) << nl;
	}
}
