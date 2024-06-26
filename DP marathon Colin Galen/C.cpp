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


const int M = 3e8+7;
const int N = 1e3+5;
const ll inf = 1e18;
const int INF = 0x3f;

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
int dp[N][8];
void solve(){
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int val;string s;
		cin >> val >> s;
		sort(all(s));
		int mask = 0;
		for(int j=0;j<3;j++){
			char x = j + 65;
			for(auto c : s){
				if(x == c){
					mask += (1 << j);
					break;
				}
			}
		}
		for(int j=0;j<8;j++){
			dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			dp[i][mask | j] = min(dp[i][mask | j], dp[i - 1][j] + val);
		}
		// for(int j=0;j<8;j++) cout << dp[i][j] << ' ';cout << nl;
	}
	cout << (dp[n][7] == dp[0][1] ? -1 : dp[n][7]);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}