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
	ll n,x,ans=0,sum=0,tmp=0;
	cin >> n >> x;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	ll l=0,r=0;
	while(r<=n){
		while(sum>x && l<r){
			tmp--;
			sum-=a[l];
			l++;
		}
		ans-=tmp*(tmp-1)/2;
		while(sum<=x && r<=n){
			tmp++;
			sum+=a[r];
			r++;
		}
		ans+=tmp*(tmp-1)/2;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
