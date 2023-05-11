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
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

int n,tt;
vector<int> a(maxn,0);
vector<int> t(4*maxn,0);
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
void update(int id,int l,int r,int u,int v){
	if(r<u || u<l) return;
	if(l==r){
		t[id]=v;
		return;
	}
	int m=(l+r)/2;
	update(id*2,l,m,u,v);
	update(id*2,m+1,r,u,v);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l,int r,int u,int v,int k){
	if(r<u || v<l || t[id]<k) return -1;
	if(u<=l && r<=v) return t[id];
	int m=(l+r)/2;
	return min(k,max(get(id*2,l,m,u,v,k),get(id*2+1,m+1,r,u,v,k)));
}
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	fast;
	indef();
	cin >> n >> tt;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while(tt--){
		int t,u,v,k;
		cin >> t;
		if(t==1){
			cin >> u >> v;
			update(1,1,n,u,v);
		}
		else{
			cin >> u >> v >> k;
			cout << get(1,1,n,u,v,k) << nl;
		}
	}
}