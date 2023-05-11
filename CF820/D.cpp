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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a[i]=x-a[i];
	}
	sort(a.begin(),a.end());
	int l=0,r=n-1,ans=0;
	while(l<r){
		if(a[l]+a[r]>=0) {ans++;r--;}
		l++;
	}
	cout << ans << "\n";
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}