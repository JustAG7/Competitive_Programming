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

ll dp[N][N];
ll a[N];
void solve(){
	int n;
	cin >> n;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sum += a[i];
	}
	for(int l = n - 1;l >= 0;l--){
		for(int r = l;r < n;r++){
			if(l == r) dp[l][r] = a[l];
			else dp[l][r] = max(a[l] - dp[l+1][r],a[r] - dp[l][r-1]);
		}
	}
	cout << (sum + dp[0][n-1]) / 2;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}