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
const int N = 205;
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

ll dp[N][N * N * 2];
ll a[N];
int n, m;
int sum = N * N;
void clear() {
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= sum * 2; j++) dp[i][j] = 0;
		dp[i][sum] = 1;
	}
}
void solve(int id){
	cin >> n >> m;
	clear();
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= m;
	}
	for (int i = 1; i <= n; i++) {
		for(int j = sum; j >= a[i] - sum; j--) {
			dp[i][j + sum] = dp[i - 1][j + sum];
			dp[i][j + sum] += dp[i - 1][j - a[i] + sum];
			dp[i][j + sum] %= M;
		}
    }
	cout << (dp[n][sum] - 1 + M) % M << nl;	
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}