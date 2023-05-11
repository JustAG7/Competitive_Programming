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
	int q;
	cin >> q;
	db ans=0;
	int n=0;
	while(q--){
		string s;
		ll x;
		cin >> s;
		if(s=="IN"){
			cin >> x;
			ans+=x;
			n++;
		}
		else if(s=="OUT"){
			cin >> x;
			ans-=x;
			n--;
		}
		else{
			//cout << ans << ' ' << n << ' ';
			db tmp=ans/n;
			if(tmp-(ll)tmp<0.5 && tmp-(ll)tmp>0) cout << (ll)tmp-1 << nl;
			else if(tmp-(ll)tmp>0.5 && tmp-(ll)tmp<1) cout << (ll)tmp+1 << nl;
			else cout << tmp << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}