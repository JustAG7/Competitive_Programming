// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 3e5+5;
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

ll dp[N][110];
int a[N];
void solve(int id){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(!a[0]) fill(dp[0], dp[0] + 105, 1);
    else dp[0][a[0]] = 1;

    for(int i = 1; i < n; i++) {
        if(a[i] > 0){
            dp[i][a[i]] = dp[i - 1][a[i]];
            if(1 <= a[i] - 1) dp[i][a[i]] += dp[i - 1][a[i] - 1];
            if(a[i] + 1 <= m) dp[i][a[i]] += dp[i - 1][a[i] + 1];
            dp[i][a[i]] %= M;
        }
        else{
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j];
                if(1 <= j - 1) dp[i][j] += dp[i - 1][j - 1];
                if(j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= M;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= M;
    }
    cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}