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
const int N = 305;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
db dp[N][N][N];
int cnt[5];
int n;

void solve(){
	cin >> n;
	for(int i=0;i<n;i++){
		int x; cin >> x;
		cnt[x]++;
	}
	// AC with VNOJ 
	// RTE (Segmentation Fault) with LQDOJ (long double issue)
	for(int k=0;k<=n;k++){
		for(int j=0;j<=n;j++){
			for(int i=0;i<=n;i++){
				if(i + j + k > n || i + j + k == 0) continue;

				db dish1 = i*1.0/n;
				db dish2 = j*1.0/n;
				db dish3 = k*1.0/n;
				if(i + j + k == 0) continue;
				if(i > 0) dp[i][j][k] += dish1*dp[i - 1][j][k];
				if(j > 0) dp[i][j][k] += dish2*dp[i + 1][j - 1][k];
				if(k > 0) dp[i][j][k] += dish3*dp[i][j + 1][k - 1];

				dp[i][j][k] += 1.0; // count the current way
				dp[i][j][k] *= n*1.0/(i + j + k); // if Kaninho get dish with 0 sushi then it's dish0 * dp[i][j][k] / n
				// or we can say dp[i][j][k] *= n / (i + j + k)
				
			}
		}
	}
	cout << fixed << setprecision(10) << dp[cnt[1]][cnt[2]][cnt[3]];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}