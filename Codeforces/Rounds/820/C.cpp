#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	string s;
	cin >> s;
	int n=s.size();
	vector<int> ans;
	char l=min(s[0],s[n-1]),r=max(s[0],s[n-1]);
	if(l==s[0]){
		for(int i=l;i<=r;i++){
			for(int j=0;j<n;j++) if(s[j]==i) ans.pb(j+1);
		}
	}
	else{
		for(int i=r;i>=l;i--){
			for(int j=0;j<n;j++) if(s[j]==i) ans.pb(j+1);
		}
	}
	cout << abs(l-r) << " " << ans.size() << "\n";
	for(auto &x : ans) cout << x << " ";
	cout << "\n";
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}