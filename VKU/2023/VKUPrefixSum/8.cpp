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

void solve(){
	int n;
	cin >> n;
	ll ans=0;
	deque<ll> dq;
	vector<ll> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	dq.pb(0);
	for(int i=1;i<n;i++){
		if(!dq.empty() && a[dq.front()]<=a[i]){
			while(!dq.empty()) dq.pop_front();
			dq.pb(i);
		}
		else if(!dq.empty() && a[dq.front()]>a[i]){
			ans+=a[i];
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}