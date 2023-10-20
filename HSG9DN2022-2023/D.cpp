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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void indef1(){
	freopen("THV.INP","r",stdin);
	freopen("THV.OUT","w",stdout);
}
ll sumdg(ll n){
	ll ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
ll numdg(ll n){
	ll ans=0;
	while(n>0){
		ans++;
		n/=10;
	}
	return ans;
}
void solve(){
	ll n;
	cin >> n;
	ll num=numdg(n),sum=sumdg(n);
	ll fact=1;
	for(ll i=2;i<num;i++) fact*=i;
	sum*=fact;
	ll tmp=sum;
	for(ll i=1;i<num;i++){
		sum+=tmp*pow(10,i);
	}
	cout << sum;
}
int main(){
	fast;	
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}