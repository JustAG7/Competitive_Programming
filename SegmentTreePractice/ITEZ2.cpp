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

vector<ll> a(maxn,0);
vector<ll> t(4*maxn,0);

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void update(ll id,ll l,ll r,ll p){
	if(p<l || r<p) return;
	if(l==r){
		t[id]=a[p];
		return;
	}
	ll m=(l+r)/2;
	update(id*2,l,m,p);
	update(id*2+1,m+1,r,p);
	t[id]=(t[id*2]+t[id*2+1]);
}
ll get(ll id,ll l,ll r,ll u,ll v){
	if(v<l || l>r || r<u) return 0;
	if(u<=l && r<=v) return t[id];
	ll m=(l+r)/2;
	return (get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v));
}
int main(){
	fast;
	indef();
	ll n,q;
	cin >> n >> q;
	while(q--){
		ll t,u,v;
		cin >> t >> u >> v;
		if(t==1){
			a[u]=v;
			update(1,1,n,u);
		}
		else cout << get(1,1,n,u,v) << nl;
	}
}