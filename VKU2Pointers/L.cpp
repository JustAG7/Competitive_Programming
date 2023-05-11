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
	ll n,x;
	cin >> n >> x;
	vector<pair<ll,ll>> a(n);
	for(int i=1;i<=n;i++){
		int tmp;
		cin >> tmp;
		a[i-1].X=tmp;
		a[i-1].Y=i;
	}
	sort(all(a));
	for(int i=0;i<n-2;i++){
		int k=n-1;
		for(int j=i+1;j<n-1;j++){
			while(a[i].X+a[j].X+a[k].X>x && k>j+1) k--;
			if(a[i].X+a[j].X+a[k].X==x){
				cout << a[i].Y << ' ' <<  a[j].Y << ' ' << a[k].Y;
				return;
			}
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