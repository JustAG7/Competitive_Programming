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
	ll ans=0;
	vector<ll> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(all(a));
    while(a[0]!=a[2]){
    	if(a[1]==a[2]){
    		ll tmp=a[1]-a[0];
    		ans+=tmp;
    		a[1]+=tmp;a[0]+=tmp;
    	}
    	else{
    		ll tmp=a[2]-a[1];
    		ans+=tmp;
    		a[0]+=tmp;a[1]+=tmp;
    	}
    	sort(all(a));
    }
    cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}