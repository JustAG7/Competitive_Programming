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
	ll m,n,s,a,b,ans=INT_MAX,mdl;
	cin >> m >> n >> s;
	if(n==0){
		cout << -1;
		return;
	}
	while(n--){
		ll tmp,stmp=s;
		cin >> a >> b;
		if(a==0 && b==0){
			cout << 1;
			return;
		}
		a%=m;b%=m;
		if((s*a+b) % m==0){
			cout << 1;
			return;
		}
		stmp=(stmp*a+b)%m;
		mdl=stmp;
		stmp=(stmp*a+b)%m;
		if(mdl==stmp) continue;
		if((m-b) % a ==0) tmp=(m-b)/a;
		else tmp=a;
		ans=min(ans,tmp);
	}
	if(ans>=INT_MAX-1) cout << -1;
	else cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}