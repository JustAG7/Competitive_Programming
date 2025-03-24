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

const int M=1e9+7;
const int maxn=5e5+5;
vector<int> a(maxn,0);
vector<int> t(4*maxn,0);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void update(int id,int l,int r,int u,int v,int k){
	if(r<u || l>v || l>r) return;
	if(u<=l && r<=v){
		a[id]+=k;
		t[id]+=k;
		return;
	}
	int m=(l+r)/2;
	update(id*2,l,m,u,v,k);
	update(id*2+1,m+1,r,u,v,k);
	t[id]=max(t[id*2],t[id*2+1])+a[id];
}
int get(int id,int l,int r,int u, int v){
	if(v<l || r<u || l>r) return -1e9;
	if(u<=l && r<=v) return t[id];
	int m=(l+r)/2;
	return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v)) + a[id];
}
int main(){
	fast;
	indef();
	int n,q;
	cin >> n >> q;
	while(q--){
		int u,v,k;
		cin >> u >> v >> k;
		update(1,1,n,u,v,k);
	}
	int tt;
	cin >> tt;
	while(tt--){
		int u,v;
		cin >> u >> v;
		cout << get(1,1,n,u,v) << nl;
	}
}
