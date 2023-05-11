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
	vector<ll> f(10000000,1);
	f[0]=1;f[1]=1;
	for(int i=2;i<10000000;i++){
		if(i&1) f[i]=f[i/2];
		else{
			f[i]=f[i/2]+f[i/2-1];
		}
	}
	for(int i=0;i<=31;i++) cout << f[i] << ' ';
	cout << nl;
	ll p,q;
	while(cin >> p >> q){
		bool dk=false;
		for(int i=0;i<10000000;i++){
			if(f[i]*q==f[i+1]*p){
				cout << i << nl;
				dk=true;
				break;
			}
		}
		if(!dk) cout << -1 << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}