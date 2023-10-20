#include<bits/stdc++.h>
using namespace std;
#define int long long
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

void solve(){
	vector<int> a(4);
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	int ans = min(a[0],a[1])+min(a[2],a[3]);
	for(int i=0;i<4;i++) ans=max(ans,a[i]);
	cout << ans*ans;
}
signed main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}