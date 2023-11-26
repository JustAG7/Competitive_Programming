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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
bool cmp(string &a,string &b){
	return a + b > b + a;
}

string a[N];
string dp[N][N];
bool dpsize[N][N];
void solve(){
	int n,l,r;
	cin >> n >> l >> r;
	for(int i=1;i<=n;i++) cin >> a[i];
	dpsize[0][0] = true;
	sort(a + 1,a + 1 + n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=r;j>=0;j--){
			dpsize[i][j] = dpsize[i - 1][j];
			if(j >= a[i].size() && dpsize[i - 1][j - a[i].size()]) dpsize[i][j] = true;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=r;j>=0;j--){
			dp[i][j] = dp[i - 1][j];
			if(j >= a[i].size() && dpsize[i][j - a[i].size()]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].size()] + a[i]);
		}
	}
	string ans = "";
	bool ok = false;
	for(int i=l;i<=r;i++)
		if(dpsize[n][i]){
			ok = true;
			ans = max(ans, dp[n][i]);
		}
	if(ok) cout << ans;
	else cout << -1;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}