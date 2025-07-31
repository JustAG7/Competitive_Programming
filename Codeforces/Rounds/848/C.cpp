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

const int M=998244353;
const int maxn=1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<ll> cnt(maxn,0);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n;
	string a,b;
	cin >> n;
	cin >> a >> b;
	ll tmp=0,x=1,y=1;
	for(int i=0;i<n;i++) tmp+=(a[i]!=b[i]);
	for(int i=n;i>=2;i--){
		x=((n*cnt[i]%M+(n*cnt[i]%M-1)*x%M)%M+M)%M;
		y=(y+(i<=tmp)*x)%M;
	}
	if(tmp==0){
		cout << 0 << nl;return;
	}
	cout << ((x*n+n+y-x)%M+M)%M-1 << nl;

}
int main(){
	fast;
	indef();
	cnt[0]=1;	
	cnt[1]=1;
	for(ll i=2;i<=maxn;i++){
		cnt[i]=M-M/i*cnt[M%i]%M;
	}
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}