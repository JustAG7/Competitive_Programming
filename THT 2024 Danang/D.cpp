#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

int dp[505][505];
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "#" + s;
	memset(dp, 0x3f, sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i] = 1;
	for(int l=n;l>=1;l--){
		for(int r=l;r<=n;r++){
			if(l == r) continue;
			dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
			if(s[l] != s[r]) dp[l][r]++;
			for(int k=l;k<=r;k++){
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
			}
		}
	}
	cout << dp[1][n] << nl;
	// for(int i=1;i<=n;i++){
	// 	// cout << s[i] << nl;
	// 	for(int j=1;j<=n;j++){
	// 		cout << dp[i][j] << ' ';
	// 	}
	// 	cout << nl;
	// }
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}