#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const int maxn=1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<vector<int>> a(maxn,vector<int> (maxn,0));
vector<int> maxrow(maxn,0);
vector<int> maxcol(maxn,0);
int n,m;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int ans=0;
	cin >> n >> m;
	vector<vector<int>> a(n,vector<int> (m,0));
	vector<vector<int>> dp(n,vector<int> (m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int h=0;
		for(int j=0;j<m;j++){
			if(a[i][j]>h){
				dp[i][j]=1;
				h=a[i][j];
			}
		}
	}
	for(int i=0;i<n;i++){
		int h=0;
		for(int j=m-1;j>=0;j--){
			if(a[i][j]>h){
				dp[i][j]=1;
				h=a[i][j];
			}
		}
	}
	for(int j=0;j<m;j++){
		int h=0;
		for(int i=0;i<n;i++){
			if(a[i][j]>h){
				dp[i][j]=1;
				h=a[i][j];
			}
		}
	}
	for(int j=0;j<m;j++){
		int h=0;
		for(int i=n-1;i>=0;i--){
			if(a[i][j]>h){
				dp[i][j]=1;
				h=a[i][j];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(dp[i][j]) ans++;
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}