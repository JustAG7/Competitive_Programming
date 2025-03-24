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
	int n,a=0,b=0;
	cin >> n;
	while(n--){
		int x;
		cin >> x;
		if(x==0) {cout << -1;return;}
		else if(x<0) a++;
		else b++;
	}
	cout << min(a,b);
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}