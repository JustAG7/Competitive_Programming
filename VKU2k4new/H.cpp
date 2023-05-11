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

const ll M=2004010501;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van
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
	ll a,b,n;
	cin >> a >> b >> n;
	ll x=b,y=1;
	ll tmp=n >> 1;
	x=((b%M)*pm(a*b,tmp,M))%M;
	if(n&1) tmp++;
	y=pm(a*b,tmp,M);
	cout << (x%M+y%M)%M;
	/* TLE
	for(int i=1;i<=n;i++){
		if(i % 2!=0){
			y=(x%M*a%M)%M;
		}
		else{
			x=(y%M*b%M)%M;
		}
	}
	*/	
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}