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
	ll n,k,ans=INT_MIN;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		ll f,t;
		cin >> f >> t;
		if(t<=k) ans=max(ans,f);
		else ans=max(ans,f-(t-k));
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt,cnt=0;
	cin >> tt;
	while(tt--){
		cnt++;
		cout << "Case #" << cnt << ": ";
		solve();
	}
}