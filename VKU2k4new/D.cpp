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

	ll n,a,b;
	cin >> n;
	if(n<=3){
		cout << "1 " << n;
		return;
	}
	ll tmp=sqrt(n+0.5);
	ll s=n*2,p=n*2;
	for(int i=2;i<=tmp+1;i++){
		for(int j=2;j<=n;j++){
			if(i*j>=n){
				if((i+j)*2<p){
					a=i;b=j;
					p=(a+b)*2;
					s=a*b;
				}
				else if((i+j)*2==p){
					if(i*j<s){
						a=i;b=j;
						p=(a+b)*2;
						s=a*b;
					}
				}
				break;
			}
		}
	}
	cout << a << ' ' << b;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}