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
	int cnt=0;
	ll a=0,b=1,c=0;
	vector<pair<ll,bool>> fibo(87,{NULL,false});
	while(c<=1000000000000000000){
		c=a+b;
		a=b;
		b=c;
		fibo[cnt].X=c;
		cnt++;
	}
	cnt--;
	//cout << fibo[cnt].X;
	ll n,end; bool dk=false;
	cin >> n;
	while(n>0){
		if(!dk){
			if(fibo[cnt].X<=n){
				fibo[cnt].Y=true;
				dk=true;
				n-=fibo[cnt].X;
				end=cnt;
			}
		}
		else{
			if(fibo[cnt].X<=n){
				fibo[cnt].Y=true;
				n-=fibo[cnt].X;
			}
		}
		cnt--;
	}
	for(int i=end;i>=0;i--){
		cout << fibo[i].Y;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}