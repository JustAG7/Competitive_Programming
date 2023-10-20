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
	int n,lt;
	string s,ans="";
	cin >> n >> s;
	int i=n-1;
	while(i>=0){
		if(s[i]!='0'){
			lt=(s[i]-'0')+96;
			ans+=(char)lt;
			i--;
		}
		else{
			lt=(s[i-2]-'0')*10;
			lt+=(s[i-1]-'0')+96;
			ans+=(char)lt;
			i-=3;
		}
	}
	reverse(ans.begin(),ans.end());
	cout << ans << "\n";
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}