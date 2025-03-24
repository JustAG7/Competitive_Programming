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
ll fact(ll n,ll m){
    ll res=1;
    for(int i=2;i<=n;i++)
        res=((res%m)*(i%m))%m;
    return res;
}
/* doi voi nhung so 0 co nhu sau 031024 hoac 001324 0
	tinh giai thua cua s.size()-1 va nhan voi a[0]
*/
void solve(){
	string s;
	ll m;
	cin >> s >> m;
	vector<int> a(10,0);
	for(int i=0;i<s.size();i++){
		int lt=s[i]-'0';
		a[lt]++;
	}
	ll num=fact(s.size(),m);
	ll nums=1;
	for(int i=0;i<=9;i++){
		if (a[i]>1) nums=(nums%m*fact(a[i],m)%m)%m;
	}
	cout << num << ' ' << nums;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}