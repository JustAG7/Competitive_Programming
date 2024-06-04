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
pair<ll,ll> dp[1 << (20)];
ll a[20];
void solve(){
	int n, x;
	cin >> n >> x;
	dp[0] = {1, 0};
	for(int i=0;i<n;i++) cin >> a[i];
	for(int mask = 1; mask < (1 << n); mask++){
		dp[mask] = {21, 0};
		for(int i=0;i<n;i++){
			if((mask >> i) & 1){
				auto [rides, weight] = dp[mask ^ (1 << i)];
				if(weight + a[i] > x){
					rides++;
					weight = min(weight, a[i]);
				}
				else weight += a[i];
				dp[mask] = min(dp[mask], {rides, weight});
			}
		}
	}
	cout << dp[(1 << n) - 1].X;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}