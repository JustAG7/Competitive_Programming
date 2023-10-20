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
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	ll n,m;
	cin >> n >> m;
	vector<ll> a(n);

	ll sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ll ans=0;
	
	while(m>0){
		bool ok=false;
		int cnt=0,sum=0;
		for(int i=0;i<n;i++){
			if(a[i]+sum<=m){
				sum+=a[i];
				cnt++;
				ok=true;
			}
		}
		if(!ok) break;
		else {ans+=n*(m/sum);m%=sum;}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}
