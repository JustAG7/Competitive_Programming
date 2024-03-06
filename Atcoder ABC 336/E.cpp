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

void solve(){
	string n;
	cin >> n;
	ll ans = 0;
	for(ll sum = 1; sum <= 9*14;sum++){
		vector<vector<vector<vector<ll>>>> dp(n.size() + 1,vector<vector<vector<ll>>> (sum + 1,vector<vector<ll>> (sum,vector<ll> (2, 0LL))));
		dp[0][0][0][1] = 1;
		for(int d=0;d<n.size();d++){
			for(int i=0;i<=sum;i++){
				for(int j=0;j<sum;j++){
					for(int f=0;f<2;f++){
						for(int t=0;t<10;t++){
							if(i + t > sum) continue;
							if(f && n[d] - '0' < t) continue;
							dp[d + 1][i + t][(j * 10 + t) % sum][f && n[d] - '0' == t] += dp[d][i][j][f];
						}
					}
				}
			}
			ans += dp[n.size()][sum][0][0];
			ans += dp[n.size()][sum][0][1];
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}