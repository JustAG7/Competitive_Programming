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
const int N = 1e3+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "friend"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
ll dp[N][N];
ll a[N];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j] = inf;
	for(int i=0;i<=n;i++) dp[i][0] = 0;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=k;j++){
			dp[i][j] = min(dp[i - 1][j], a[i] - a[i - 1] + dp[i - 2][j - 1]);
		}
	}
	cout << dp[n][k];	
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
