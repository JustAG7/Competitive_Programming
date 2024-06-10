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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int dp[N];
string a[N];
void solve(){
	int n;
	string s;
	cin >> n >> s;
	int m = s.size();
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	set<string> st;
	for(int i=0;i<n;i++){
		string t;cin >> t;
		st.insert(t);
	}
	for(int i=1;i<=m;i++){
		int res = M;
		for(int j=2;j<=min(i, 20);j++){
			string str = s.substr(i - j, j);
			res = min(res, dp[i - j + 1]);
			if(i == j) res = 0;
			if(st.find(str) != st.end()){
				dp[i] = min(dp[i], res) + 1;
			}
		}
	}
	cout << dp[m];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}