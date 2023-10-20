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
const int N = 1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int dp[N];
int a[N];
// O(n^2) just if a[i] > a[j] for 0<j<i and 0<i<=n
void solve1(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) dp[i] = 1;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i] > a[j]) dp[i] = max(dp[i],dp[j] + 1);
		}
	}
	cout << *max_element(dp+1,dp+1+n);
}
// O(n*log(n)) using binary search to find the nearest and minimum number that > a[i]
// for 1 <= i <= n

void solve2(){
	int n;
	cin >> n;
	memset(dp,M,sizeof(dp));
	dp[0] = INT_MIN;
	int ans = 1;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		int pos = lower_bound(dp,dp+N,x) - dp;
		ans = max(ans, pos);
		dp[pos] = x;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve2();
}