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
const int N = 1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int dp[N];
void solve(){
	int n;
	cin >> n;
	memset(dp,M,sizeof(dp));
	// M = 1e9 + 7 (số mod lấy làm hằng số, vì nhác ghi hằng số max)
	dp[0] = 0;
	for(int i=0;i<=n;i++){
		for(char c : to_string(i)){
			dp[i] = min(dp[i],dp[i - (c - '0')] + 1);
		}
	}
	cout << dp[n];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}