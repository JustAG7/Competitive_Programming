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
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

ll dp[105][N];
int a[105];
void solve(){
	//dp[i][j] = số cách chia j kẹo cho i đứa
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++) cin >> a[i];
	ll ans = 0;
	dp[0][0] = 1;
	for(int i=1;i<=n;i++){
		ll pref[k + 1];
		pref[0] = dp[i - 1][0];
		for(int j=1;j<=k;j++){
			pref[j] = (pref[j - 1] + dp[i - 1][j]) % M;
		}

		for(int j=0;j<=k;j++){
			ll tmp = pref[j];
			if(j - a[i] - 1 >= 0){
				tmp = (tmp - pref[j - a[i] - 1] + M) % M;
			}
			dp[i][j] = tmp;
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
