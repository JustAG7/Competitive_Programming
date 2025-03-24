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
const int N = 3e3+5;

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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string ans = "";
	int i = n, j = m;
	while(i>0 && j>0){
		if(a[i - 1] == b[j - 1]){
			ans += a[i - 1];
			i--;j--;
		}
		else{
			if(dp[i - 1][j] > dp[i][j - 1]) i--;
			else j--;
		}
	}
	reverse(all(ans));
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}