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

map<int, int> dp[2][105];
ll M = 1e18;
void solve(int id){
	int n, k;
	cin >> n >> k;

	// note: this is pretty much from chatGPT (don't know if dp map data structures will work)
	for(int i = 0; i < 2; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j].clear();
		}
	}
	// dp[(cur / prev) pigeon][hole][mask]
	for (int i = 1; i <= n; i++) {
        int mask = (1 << (i - 1));
        dp[1][i][mask] = 1;
    }

    for(int i = 2; i <= k; i++) {
    	int cur = i % 2;
    	int prev = 1 - cur;

    	for(int j = 1; j <= n; j++) {
    		for(auto &[mask, cnt] : dp[prev][j]) {
    			if (j > 1) {
    				int new_mask = mask | (1 << (j - 2)); // left
    				dp[cur][j - 1][new_mask] = (dp[cur][j - 1][new_mask] + cnt) % M;
                }
                if (j < n) {
                	int new_mask = mask | (1 << j); // right
                	dp[cur][j + 1][new_mask] = (dp[cur][j + 1][new_mask] + cnt) % M;
                }
    		}
    	}
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
    	ans += dp[k % 2][i][(1 << n) - 1];
    	ans %= M;
    }
    cout << ans << nl;
}
int main(){
	fast;
	indef();
	M += 9;
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}