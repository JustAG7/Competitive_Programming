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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};


vector<pair<int,int>> a(maxn);
vector<int> ans(maxn);
vector<int> t[4*maxn];

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void build(int id,int l,int r){
	if(l==r){
		t[id].pb(a[l].Y);
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	merge(all(t[id*2]),all(t[id*2+1]),back_inserter(t[id]));

}

int get(int id,int l,int r,int u,int v,int k){
	if(l==r){
		return t[id][0];
	}
	int m=(l+r)/2;
	int pos = upper_bound(all(t[id*2]),v) - lower_bound(all(t[id*2]),u);

	if(pos>=k) return get(id*2,l,m,u,v,k);
	else return get(id*2+1,m+1,r,u,v,k-pos);

}
int main(){
	fast;
	indef();
	int n,q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i].X;
		a[i].Y=i;
		ans[i]=a[i].X;
	}
	sort(a.begin()+1,a.begin()+1+n);

	build(1,1,n);

	while(q--){
		int l,r,k;
		cin >> l >> r >> k;
		int pos = get(1,1,n,l,r,k);
		cout << ans[pos] << nl;
	}

}