#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
const int N = 100*1000 + 5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}


bool dp[105][N];
int a[105];
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	dp[0][0] = true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=100*1000;j++){
			if(j - a[i] >= 0 && dp[i - 1][j - a[i]]) dp[i][j] = true;
			else dp[i][j] = dp[i - 1][j];
		}
	}
	vector<int> ans;
	for(int i=1;i<=100*1000;i++){
		if(dp[n][i]) ans.pb(i);
	}
	cout << ans.size() << nl;
	for(auto x : ans) cout << x << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}