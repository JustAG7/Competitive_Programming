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
	int n,ans=INT_MAX;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(all(a));
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		int pos=lower_bound(all(a),0-x) - a.begin();
		if(pos==n) pos--;
		if(pos>0) ans=min(ans,abs(x+a[pos-1]));
		ans=min(ans,abs(x+a[pos]));
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}