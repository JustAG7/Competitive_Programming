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
void solve(){
	ll n,ans=0;
	cin >> n;
	for(ll i=5;n/i>=1;i*=5){
		ans+=n/i;
	}
	cout << ans ;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}