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
const int maxn=1e+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<ll> t(4*maxn,0);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("SUM.INP","r",stdin);
		freopen("SUM.OUT","w",stdout);
	#endif
}
void update(int id,int l,int r,int u,int v){
	if(r<u || l>u) return;
	if(l==r){
		t[id]=v;
		return;
	}
	int m=(l+r)/2;
	update(id*2,l,m,u,v);
	update(id*2+1,m+1,r,u,v);
	t[id]=t[id*2]+t[id*2+1];
}
ll get(int id,int l,int r,int u,int v){
	if(l>v || r<u) return 0;
	if(u<=l && r<=v) return t[id];
	int m=(l+r)/2;
	return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
void solve(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		char q;
		int u,v;
		cin >> q >> u >> v;
		if(q=='Q') cout << get(1,1,n,u,v) << nl;
		else update(1,1,n,u,v);
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}