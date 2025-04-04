#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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

void solve(int id){
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n + 5, vector<int> (m + 5, M));
	dp[0][0] = 0;
	for(int i = 0; i < n; i++) dp[i + 1][0] = dp[i][0] + (a[i] != c[i]);
	for(int i = 0; i < m; i++) dp[0][i + 1] = dp[0][i] + (b[i] != c[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int k = i + j - 1; 
			dp[i][j] = min(dp[i - 1][j] + (a[i - 1] != c[k]), dp[i][j - 1] + (b[j - 1] != c[k]));
		}
	}
	cout << dp[n][m] << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}