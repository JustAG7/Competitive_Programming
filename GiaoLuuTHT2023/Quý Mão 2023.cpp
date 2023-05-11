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

const int M=1e9+7;
const int maxn=1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vector<bool> prime(maxn,true);
void sieve(){
	prime[1]=false;
	for(int i=2;i*i<=maxn;i++){
		if(prime[i]){
			for(int j=i*i;j<=maxn;j+=i){
				prime[j]=false;
			}
		}
	}
}
void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		if(prime[a[i]]){
			ll l=0,r=0;
			for(int j=i-k;j>=0;j-=k){
				if(a[j]==1) l++;
				else break;
			}
			for(int j=i+k;j<n;j+=k){
				if(a[j]==1) r++;
				else break;
			}
			ans+=l+r+l*r;
		}

	}
	
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	sieve();
	int tt;
	cin >> tt;
	while(tt--) solve();
}
