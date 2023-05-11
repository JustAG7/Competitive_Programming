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
	cin >> n;
	vector<db> a(n),b(n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		a[i]--;b[i]--;
	}
	sort(all(a),greater<db>());
	sort(all(b),greater<db>());
	db ans=0, ma=0,mb=0;
	int l=0,r=0;
	while(l<n){
		ma+=a[l];
		l++;	
		while(r<n && min(ma-r,mb-l)<min(ma-r-1,mb+b[r]-l-1)){
			mb+=b[r];
			r++;
		}
		ans=max(ans,min(ma-r,mb-l));
	}
	cout << fixed << setprecision(4);
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}