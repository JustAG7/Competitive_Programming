#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long

const int N = 2e5+5;

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
ll a[N], b[N];
void solve(){
	ll n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		cin >> b[i];
		b[i] = max(b[i - 1], b[i]);
	}
	ll ans = 0, temp = 0;
	for(int i=1;i<=n;i++){
		temp += a[i];
		ll count = k - i;
		if(count < 0) break;
		ll value = temp + count * b[i];
		ans = max(ans, value);
	}
	cout << ans;
}
int main(){
	fast;
	indef(); // xoa dong nay neu muon tat file
	solve();
}