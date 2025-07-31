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

array<int, 3> dp[N];
int check(int x,int y){
	return ((x - y + 3) % 3 == 1 ? 1 : x == y ? 0 : -M);
}
void solve(){
	int n;
	string s;
	cin >> n >> s;
	// dp[i, j]: the amount of wins if ith hand is j (j: {R, P, S})
	memset(dp, -M, sizeof dp);
	for(int i=0;i<3;i++) dp[0][i] = 0;
	for(int i=0;i<n;i++){
		int x = (s[i] == 'R' ? 0 : s[i] == 'P' ? 1 : 2);
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(j == k) continue;
				dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + check(k, x));
			}
		}
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]});
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}