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
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
void solve(){
	int n,ans=0;
	cin >> n;
	unordered_map<int,int> mp;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==0) a[i]=-1;
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0) ans=max(ans,i);
		else{
			if(mp.count(a[i])>0) ans=max(ans,i-mp[a[i]]);
			else mp[a[i]]=i;
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}