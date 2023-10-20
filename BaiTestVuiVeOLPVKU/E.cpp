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
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
ll tong(ll n){
	return n%M*((n-1)%M)%M*((M+1)/2)%M;
}
void solve(){
	ll n,ans=0;
	cin >> n;
	for(ll i=1;i<=n;i++){
		ll j=n/(n/i);
		ans+=(n/i)%M*(tong(j+1)-tong(i)+M)%M;
		i=j;
	}
	cout << ans%M;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}