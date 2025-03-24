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
	int n,k,ans=0;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	int tmp=1;
	for(int i=0;i<n;i++){
		if(tmp==a[i]){
			ans++;
			tmp++;
		}
	}
	ans=n-ans;
	if(ans % k==0) ans=ans/k;
	else ans=ans/k+1;
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}