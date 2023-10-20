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

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,k;
	ll tmp,ans=0;
	cin >> n >> k;
	vector<ll> a(n+5,0);
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		if(i % k==0) a[k]=max(a[i],a[k]);
		else a[i % k]=max(a[i],a[i % k]);
	}

	for(int i=1;i<=k;i++){
		ans+=a[i];
	}
	cout << ans << "\n";
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}