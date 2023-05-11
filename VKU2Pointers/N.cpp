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
	ll n,m,k,ans=0;
	cin >> n >> m >> k;
	vector<ll> a(n),b(m);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	sort(all(a));sort(all(b));
	ll l=0,r=0;
	while(l<n && r<m){
		if(a[l]-k<=b[r] && b[r]<=a[l]+k){
			ans++;
			l++;
			r++;
		}
		else if(a[l]>b[r]) r++;
		else l++;
		//cout << l << ' ' << r << nl;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}