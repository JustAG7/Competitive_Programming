// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define int long long
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
const int N = 5e3+5;
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

int dp[N];
int n;
vector<array<int, 3>> v;
int get(bool isLen) {
    for (int i = 0; i < n; i++) {
        dp[i] = isLen ? 1 : v[i][2];

        for (int j = 0; j < i; j++) {
            if (v[i][0] < v[j][0] && v[i][1] < v[j][1]) {
                if(isLen) dp[i] = max(dp[i], dp[j] + 1);
                else dp[i] = max(dp[i], dp[j] + v[i][2]);
            }
        }
    }

    return *max_element(dp, dp + n);
}
void solve(int id){
	cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, h; 
        cin >> a >> b >> h;
        v.push_back({a, b, h});
    }

    sort(all(v), [](const auto &a, const auto &b) {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] > b[0];
    });
    cout << get(1) << ' ' << get(0);
    
}
signed main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}