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
	ll n,k,ans=0,tmp=0;
	cin >> n >> k;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	map<ll,ll> mp;
	ll l=0,r=0;
	while(l<n){
		while(r<n && tmp + (mp[a[r]] == 0) <= k){
			mp[a[r]]++;
			tmp+=(mp[a[r]] == 1);
			r++;
		}
		ans+=r-l;   
        tmp-=(mp[a[l]] == 1);
        mp[a[l]]--, l++;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
