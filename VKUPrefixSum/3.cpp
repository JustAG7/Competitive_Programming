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
void solve(){
	ll n;
	cin >> n;
	vector<ll> a(n+1,0);
	vector<ll> b(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i]=b[i-1] + a[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i]*(b[n]-b[i]);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
