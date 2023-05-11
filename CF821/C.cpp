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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	vector<pair<int,int>> ans;
	ans.pb({0,n-1});
	if(n==1){
		cout << 0 << "\n";
		return;
	}
	if((a[0]+a[n-1]) % 2!=0) a[n-1]=a[0];
	else a[0]=a[n-1];
	for(int i=1;i<n-1;i++){
		if((a[0]+a[i]) % 2 !=0) ans.pb({0,i});
		else ans.pb({i,n-1});
	}
	cout << ans.size() << '\n';
	for(auto &x : ans) cout << x.X+1 << " " << x.Y+1 << '\n';
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}