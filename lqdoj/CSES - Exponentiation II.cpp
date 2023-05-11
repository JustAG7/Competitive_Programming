#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll pm(ll x,ll y,ll M){
	ll ans=1;
	x%=M;
	if(x==0) return 0;
	while(y>0){
		if(y & 1) ans=(ans*x)%M;
		y=y >> 1;
		x=(x*x)%M;
	}
	return ans;
}
void solve(){
	ll a,b,c,tmp;
	cin >> a >> b >> c;
	if(b==0 && c==0) tmp=1;
	else tmp=pm(b,c,M-1);
	if(a==0 && tmp==0) cout << 1 << "\n";
	else cout << pm(a,tmp,M) << "\n";
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}