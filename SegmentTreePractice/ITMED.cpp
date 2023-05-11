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
const ll maxn=1e5+5;

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	ll n,k,ans=0;
	cin >> n >> k;
	vector<ll> a(n+1); 
	vector<ll> f(n+5);
	deque<int> dq;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		while(!dq.empty() && f[dq.back()]<f[i-1]) dq.pop_back();
		dq.pb(i-1);
		while (!dq.empty() && dq.front() + k <= i-1) dq.pop_front(); 
		f[i]=max(f[dq.front()],0LL)+a[i];
		ans=max(ans,f[i]);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	ll tt=1;
	while(tt--) solve();
}