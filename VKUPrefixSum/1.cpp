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
	int n;
	cin >> n;
	vector<int> a(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		a[i]+=a[i-1];
	}
	int ans=0,l=0,mid=1,r=n;
	while(mid<r){
		if(a[mid]-a[l]==a[r]-a[mid]) ans++;
		mid++;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}