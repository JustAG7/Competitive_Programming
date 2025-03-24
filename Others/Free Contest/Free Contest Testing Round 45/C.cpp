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
const int N = 5e3+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ll dp[205][N], b[N][205], pre[N], a[N];
ll dist[N][N];
int n, m;
ll sum = 0;
void calc() {
	for(int i = 1; i <= n; i++) {
		ll res = 0;
		for(int j = i + 1; j <= n; j++) {
			res += a[j - 1];
			dist[i][j] = res;
			// cout << "dist (" << i << ',' << j << ") " << dist[i][j] << nl;
		}
		// cout << nl;
	}
}
ll distance(int x, int y) {
	if(x > y) swap(x, y);
	return dist[x][y];
}
void solve(int id){
	cin >> n >> m;
	for(int i = 1; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		pre[i] = pre[i - 1] + a[i];
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> b[i][j];
	for(int i = 1; i <= n; i++)  
		dp[1][i] = b[i][1];
	calc();
	for(int i = 2; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			ll res = 0;
			for(int k = 1; k <= n; k++) {
				// cout << "dist (" << j << ',' << k << ") " << distance(j, k) << nl;
				if(j == k) res = max(res, dp[i - 1][k]);
				else res = max(res, dp[i - 1][k] - distance(k, j));
			}
			dp[i][j] = res + b[j][i];
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, dp[m][i]);
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}