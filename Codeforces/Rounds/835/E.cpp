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

ll sum(int n,vector<int> a){
	ll ans = 0,cnt = 0;
	for(int i=n-1;i>=0;i--){
		if(a[i]==0) cnt++;
		else ans+=cnt;
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	ll ans= sum(n,a);
	for(int i=0;i<n;i++){
		if(a[i]==0){
			a[i]=1;
			ans=max(ans,sum(n,a));
			a[i]=0;
			break;
		}
	}
	for(int i=n-1;i>=0;i--){
		if(a[i]==1){
			a[i]=0;
			ans=max(ans,sum(n,a));
			break;
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}