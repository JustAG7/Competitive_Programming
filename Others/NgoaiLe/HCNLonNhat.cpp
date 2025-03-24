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
	int n,m;
	int ans=0;
	cin >> n >> m;
	vector<vector<int>> a(n+1,vector<int> (m+1,0));
	vector<vector<int>> dp(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=a[i][j]==0 ? 0 : dp[i-1][j]+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		sort(all(dp[i]));
	}
	// check prefix array
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << dp[i][j] << ' ';
		}
		cout << nl;	
	}
	*/
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans=max(ans,(m-j+1)*dp[i][j]);
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}