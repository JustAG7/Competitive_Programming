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
	int n,k=0;
	cin >> n;
	vector<int> a(n);
	vector<int> ans;
	for(int i=0;i<n;i++) cin >> a[i];
	ans.pb(a[0]);
	for(int i=0;i<n-1;i++){
		if(__gcd(a[i],a[i+1])==1){
			ans.pb(a[i+1]);
		}
		else{
			k++;
			ans.pb(1);
			ans.pb(a[i+1]);
		}
	}
	cout << k << nl;
	for(auto x : ans) cout << x << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}