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
const int N = 5e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int dp[N][N];
void solve(){
	string a,b;
	cin >> a >> b;
	int n = a.size(), m = b.size();
	memset(dp,M,sizeof(dp));
	dp[0][0] = 0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i == 0) dp[i][j] = j;
			else if(j == 0) dp[i][j] = i;
			else if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min(dp[i - 1][j - 1],min(dp[i - 1][j], dp[i][j - 1])) + 1;
		}
	}
	cout << dp[n][m];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}