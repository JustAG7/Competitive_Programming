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
	ll y;
	cin >> y;
	if(y==1){
		cout << 0;
		return;
	}
	vector<ll> a(11,0);
	ll tmp=1;
	for(int i=1;i<=9;i++){
		tmp*=i;
		a[i]=tmp;
	}
	a[0]=1;
	vector<ll> ans;
	vector<ll> onezero;
	int ind=9;
	while(y>0){
		if(ind>1){
			while(a[ind]<=y){
				ans.pb(ind);
				y-=a[ind];
			}
		}
		else{
			if(a[ind]<=y){
				onezero.pb(1);
				y--;
			}
			while(y>0){
				onezero.pb(0);
				y--;
			}
		}
		ind--;
	}
	sort(all(ans));
	for(int i=1;i<=onezero.size();i++){
		if(i==1) cout << 1;
		else cout << 0;
	}
	for(int x : ans) cout << x;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}