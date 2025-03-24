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
const int N = 2e5+5;
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

string t = "yugihacker";
ll dp[N][15];

void solve(){
	string s;
	cin >> s;
	int n = s.size();
	for(int i = 1; i <= n; i++) 
		if(s[i - 1] == 'y') dp[i][0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			if (s[i - 1] == t[j - 1]) {
			cout << s[i - 1] << ' ' << t[j - 1] << ' ';
            cout << i << ' ' << j << nl;
                dp[i][j] += dp[i - 1][j - 1];
			}
            dp[i][j] %= M;
            // cout << dp[i][j] << ' ';
		}
		// cout << nl;
		dp[i][0] += dp[i - 1][0];
	}
	cout << dp[n][10];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}