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

vector<ll> a(maxn,0);
vector<ll> t(4*maxn,0);
vector<ll> b(maxn,0);
vector<ll> c(maxn,1);
int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int m=(l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id]=(t[id*2]+t[id*2+1])%M;
}

void update1(int id,int l,int r,int u,int v,int k){
	if(r<u || v<l) return;
	if(u<=l && r<=v){
		t[id]+=k;
		b[id]+=k;
		return;
	}
	int m=(l+r)/2;
	update1(id*2,l,m,u,v,k);
	update1(id*2,m+1,r,u,v,k);
	t[id]=(t[id*2]+t[id*2+1]+b[id])%M;
}
void update2(int id,int l,int r,int u,int v,int k){
	if(r<u || v<l) return;
	if(u<=l && r<=v){
		t[id]=(t[id]%M*k%M)%M;
		c[id]=(c[id]%M*k%M)%M;
		return;
	}
	int m=(l+r)/2;
	update2(id*2,l,m,u,v,k);
	update2(id*2+1,m+1,r,u,v,k);
	t[id]=((t[id*2]%M + t[id*2+1]%M)*(k%M))%M;
}
void update3(int id,int l,int r,int u,int v,int k){
	if(r<u || v<l) return;
	if(u<=l && r<=v){
		t[id]=k;
		c[id]=1;
		b[id]=0;
		return;
	}
	int m=(l+r)/2;
	update3(id*2,l,m,u,v,k);
	update3(id*2+1,m+1,r,u,v,k);
	t[id]=(t[id*2]+t[id*2+1])%M;
}
ll get(int id,int l,int r,int u,int v){
	if(r<u || v>l) return 0;
	if(u<=l && r<=v) return t[id];
	int m=(l+r)/2;
	return (get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v))%M;
}
int main(){
	fast;
	indef();
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while(q--){
		int t,u,v,x;
		cin >> t;
		if(t==1){
			cin >> u >> v >> x;
			update1(1,1,n,u,v,x);
		}
		else if(t==2){
			cin >> u >> v >> x;
			update2(1,1,n,u,v,x);
		}
		else if(t==3){
			cin >> u >> v >> x;
			update3(1,1,n,u,v,x);
		}
		else{
			cin >> u >> v;
			cout << get(1,1,n,u,v) << nl;
		}
	}
}