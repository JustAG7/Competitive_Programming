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
	ll n,m,x;
	cin >> n >> m;
	vector<pair<ll,ll>> a(n);
	for(int i=1;i<=n;i++){
		cin >> x;
		a[i-1].X=x;
		a[i-1].Y=i;
	}
	sort(all(a));
	int l=0,r=n-1;
	/*
	for(int i=0;i<n;i++){
		cout << a[i].X << ' ' << a[i].Y << nl;
	}
	*/
	while(l<r){
		if(a[l].X + a[r].X > m) r--;
		else if (a[l].X + a[r].X < m) l++;
		else{
			cout << min(a[l].Y,a[r].Y) << ' ' << max(a[l].Y,a[r].Y);
			return;
		}
	}
	cout << "IMPOSSIBLE";
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}