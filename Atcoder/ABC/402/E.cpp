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
#define MASK(x, i) (((x) >> i) & 1)

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

db dp[5005][(1 << 8) + 5];
db s[10], p[10], c[10];
void solve(int id){
	int n, x;
	cin >> n >> x;
	for(int i = 0; i < n; i++) {
		cin >> s[i] >> c[i] >> p[i];
		p[i] /= 100;
	}
	for(int i = 0; i <= x; i++) {
		for(int j = 0; j < (1 << n); j++) {
			for(int k = 0; k < n; k++) {
				int cost = i - c[k];
				int mask = j | (1 << k);
				if(cost < 0 || mask == j) continue;
				db val = p[k] * (dp[cost][mask] + s[k]) + (1.0 - p[k]) * (dp[cost][j]);
				dp[i][j] = max(dp[i][j], val);
			}
		}
	}
	cout << fixed << setprecision(6) << dp[x][0] << nl;
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