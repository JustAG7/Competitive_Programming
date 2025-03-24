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
int dp[N][N];
void solve(){
	int a,b;
	cin >> a >> b;
	for(int i=0;i<=a;i++){
		for(int j=0;j<=b;j++){
			if(i == j) dp[i][j] = 0;
			else{
				dp[i][j] = M;
				// cat chieu dai
				for(int k = 1;k < i;k++)
					dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
				// cat chieu rong
				for(int k = 1;k < j;k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
			}
		}
	}
	cout << dp[a][b];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}