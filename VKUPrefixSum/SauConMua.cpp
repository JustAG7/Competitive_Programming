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
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n;
	cin >> n;
	vector<int> a(n+2);
	vector<int> maxl(n+2,0),maxr(n+2,0);
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) maxl[i]=max(maxl[i-1],a[i]);	
	for(int i=n;i>=1;i--) maxr[i]=max(maxr[i+1],a[i]);
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(maxl[i-1]>a[i] && maxr[i]>a[i]) 
			ans+=min(maxl[i-1],maxr[i])-a[i];
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}