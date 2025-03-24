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
const int N = 1e5+5;
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
ll dp[N];
int c[55], h[55];
void solve(){
	int n, x;
	cin >> n >> x;
	ll sum = 0;
	for(int i=0;i<n;i++){
		cin >> c[i] >> h[i];
		sum += h[i];
	}
	for(int i=1;i<=sum+1;i++) dp[i] = inf;
	for(ll i=0;i<n;i++){
		for(int j=sum;j>=h[i];j--){
			if(dp[j - h[i]] + c[i] <= i * x){
				dp[j] = min(dp[j], dp[j - h[i]] + c[i]);
			}
		}
	}
	for(int i=sum;i>=0;i--){
		if(dp[i] != inf) return cout << i << nl, void();
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}