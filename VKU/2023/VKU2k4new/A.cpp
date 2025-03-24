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
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van
void solve(){
	ll a,b,x,y;
	cin >> a >> b >> x >> y;
	ll x1=min(x,y),x2=max(x,y);
	ll ans=min(a+x1,b+x1);
	ans=max(ans*ans,x2*x2);
	x1=min(a,b),x2=max(a,b);
	ll tmp=min(x+x1,y+x1);
	ans=max(ans,max(tmp*tmp,x2*x2));
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}