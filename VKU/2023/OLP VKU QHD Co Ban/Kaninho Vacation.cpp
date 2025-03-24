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
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll dp[N][4];
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin >> a >> b >> c;
		dp[i][1] = max(dp[i-1][2],dp[i-1][3]) + a;
		dp[i][2] = max(dp[i-1][1],dp[i-1][3]) + b;
		dp[i][3] = max(dp[i-1][1],dp[i-1][2]) + c;
	}
	cout << max(dp[n][1],max(dp[n][2],dp[n][3]));

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}