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
ll dp[N];
ll a[N];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	dp[1] = abs(a[1] - a[0]);
	for(int i=2;i<n;i++){
		ll temp = 1e18;
		for(int j=max(0,i - k);j<i;j++){
			temp = min(temp, dp[j] + abs(a[i] - a[j]));
		}
		dp[i] = temp;
	}
	cout << dp[n-1];

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}