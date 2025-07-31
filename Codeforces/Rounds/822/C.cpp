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
	int n;
	string s;
	cin >> n >> s;
	s="$"+s;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			if(s[j]=='1') break;
			if(a[j]==0) a[j]=i;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='0') ans+=a[i];
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}