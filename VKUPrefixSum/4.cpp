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
	ll n,m;
	cin >> n >> m;
	n=max(n,m);
	vector<ll> a(n+2,0);
	while(m--){
		int l,r;
		cin >> l >> r;
		a[l]++;a[r+1]--;
	}
	for(int i=1;i<=n;i++) a[i]+=a[i-1];
	vector<ll> b(n+2,0);
	for(int i=1;i<=n;i++) b[a[i]]++;
	for(int i=n-1;i>=1;i--) b[i]+=b[i+1];
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		cout << b[n] << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
