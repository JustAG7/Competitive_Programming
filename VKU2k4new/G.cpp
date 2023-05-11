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
#define maxn 20000005

const ll M=1e9+7;
vector<bool> prime(maxn,true);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void sieve(){
	prime[1]=false;
	for(int i=2;i*i<=maxn;i++)
		if(prime[i])
			for(int j=i*i;j<=maxn;j+=i)
				prime[j]=false;
}
//tt=1 neu ko co truy van
bool check(int n){
	if(n<5) return false;
	int l,r=maxn-5;
	for(int i=n-1;i>=2;i--){
		if(prime[i]){
			l=i;
			break;
		}
	}
	for(int i=n+1;i<=maxn;i++){
		if(prime[i]){
			r=i;
			break;
		}
	}
	if((l+r)==n*2) return true;
	return false;
}
void solve(){
	int n;
	cin >> n;
	if(prime[n]){
		if(check(n)) cout << "YES" << nl;
		else cout << "NO" << nl;
	}
	else cout << "NO" << nl;
}
int main(){
	fast;
	indef();
	sieve();
	int tt;
	cin >> tt;
	while(tt--) solve();
}