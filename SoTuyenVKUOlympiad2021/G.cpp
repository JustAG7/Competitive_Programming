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
const int maxn=2e7+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
vector<int> prime(maxn,1);
void sieve(){
	prime[0]=0;
	prime[1]=0;
	for(int i=2;i*i<=maxn;i++){
		if(prime[i]){
			for(int j=i*i;j<=maxn;j+=i){
				prime[j]=0;
			}
		}
	}

}
void solve(){
	int n;
	cin >> n;
	if(!prime[n] || n<=2){
		cout << "NO\n";
		return;
	}
	int l=2,r=2e7+3;
	for(int i=n-1;i>=2;i--){
		if(prime[i]){
			l=i;
			break;
		}
	}
	for(int i=n+1;i<=2e7;i++){
		if(prime[i]){
			r=i;
			break;
		}
	}
	if(l+r==n*2){
		cout << "YES\n";
	}
	else cout << "NO\n";
}
int main(){
	fast;
	indef();
	sieve();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}