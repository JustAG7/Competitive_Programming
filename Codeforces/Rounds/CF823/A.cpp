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
	int n,c;
	cin >> n >> c;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(all(a));
	int ans=0,tmp=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i-1]){
			ans+=min(tmp,c);
			tmp=1;
		}
		else tmp++;
	}
	cout << ans+min(tmp,c) << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}