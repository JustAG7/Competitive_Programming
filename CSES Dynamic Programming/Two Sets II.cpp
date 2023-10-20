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
const int N = 505;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll dp[N][N*N];
void solve(){
	int n;
	cin >> n;
	int sum = n*(n+1)/2;
	if(sum&1){
		cout << 0;
		return;
	} 
	sum /= 2;
	dp[0][0] = 1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=sum;j++){
			dp[i][j] = dp[i-1][j] % M;
      		if(j - i >= 0) (dp[i][j] += dp[i-1][j - i]) %= M;
		}
	}
	cout << dp[n - 1][sum];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}