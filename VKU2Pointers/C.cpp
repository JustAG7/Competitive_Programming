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
	int n,m,x,ans=0;
	cin >> n >> m;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> x;
		mp[x]++;
	}
	for(int i=0;i<m;i++){
		cin >> x;
		ans+=mp[x]; 
	}
	cout << ans; 
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}