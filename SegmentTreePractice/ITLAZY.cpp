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
const ll maxn=5e5+5;
vector<ll> a(maxn,0);
vector<ll> t(4*maxn,0);
vector<ll> b(4*maxn,0);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void build(ll id,ll l,ll r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	ll m=(l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
void update(ll id,ll l,ll r,ll u,ll v,ll k){
	if(r<u || l>v || l>r) return;
	if(u<=l && r<=v){
		b[id]+=k;
		t[id]+=k;
		return;
	}
	ll m=(l+r)/2;
	update(id*2,l,m,u,v,k);
	update(id*2+1,m+1,r,u,v,k);
	t[id]=max(t[id*2],t[id*2+1])+b[id];
}
ll get(ll id,ll l,ll r,ll u, ll v){
	if(v<l || r<u || l>r) return -1e9+7;
	if(u<=l && r<=v) return t[id];
	ll m=(l+r)/2;
	return max(get(id*2,l,m,u,v),get(id*2+1,m+1,r,u,v)) + b[id];
}
int main(){
	fast;
	indef();
	ll n;
	cin >> n;
	for(ll i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	ll q;
	cin >> q;
	while(q--){
		ll t,u,v,k;
		cin >> t;
		if(t==1){
			cin >> u >> v >> k;
			update(1,1,n,u,v,k);
		}
		else{
			cin >> u >> v;
			cout << get(1,1,n,u,v) << nl;
		}
	}
}