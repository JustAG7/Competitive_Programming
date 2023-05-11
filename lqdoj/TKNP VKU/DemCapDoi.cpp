#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define pb push_back
#define db double
#define fi first
#define se second


const ll MOD=1000000007;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,k,ans=0;
	cin >> n >> k;
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
    for(int i=0;i<n-1;i++){
   		int x=a[i],y=k-x;
   		if(mp[y]>0){
   			if(y==x) ans+=mp[y]-1;
   			else ans+=mp[y];
  		}
   		mp[x]--;
   	}
   	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
