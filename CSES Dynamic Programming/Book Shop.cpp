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
int dp[N];
int weight[N];
void solve(){
	int n,x;
	cin >> n >> x;
	for(int i=0;i<n;i++) cin >> weight[i];
	for(int i=0;i<n;i++){
		int val;cin >> val;
		for(int j=x;j>=weight[i];j--){
			dp[j] = max(dp[j],dp[j - weight[i]] + val);
		}
	}
	cout << dp[x];

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}