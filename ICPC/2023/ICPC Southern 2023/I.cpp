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
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 5e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[N];
ll dp[N][N];
void add(ll &a,ll b){
	a += b;
	a %= M;
}
void solve(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
	const int LIM = 5001;
	dp[0][0] = 1;
	ll ans = 0;
    for (int i = 0; i <= n; i++) {
    	if (i < n) {
			for (int s = a[i+1] + 1; s <= LIM; s++)
				add(ans, dp[i][s]);
    	}
     	for (int s = 0; s <= LIM; s++) {
	        if (!dp[i][s]) continue;
	        add(dp[i+1][s], dp[i][s]);
	        add(dp[i+1][min(LIM, s+a[i+1])], dp[i][s]);
      	}
    }
    cout << ans;
}
int main(){
	fast;
	// indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}