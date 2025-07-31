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

using int128 = __int128;
int128 memo[35][10][2];

int n;
string s;
int cur;
int128 dp(int pos, int sum, bool under) {
    if(pos == cur + 1) {
        return sum == 0;
    }

    int128 &ans = memo[pos][sum][under];
    if(ans != -1) return ans;

    ans = 0;
    int lim = under ? 9 : s[pos] - '0';

    for(int i = 0; i <= lim; i++) {
        ans += dp(pos + 1, (sum * 2 + i) % 10, under || (i < lim));
    }

    return ans;
}

void print(int128 x) {
    if (x == 0) {
        cout << "0";
        return;
    }
    string res;
    while (x > 0) {
        res += (x % 10) + '0';
        x /= 10;
    }
    reverse(res.begin(), res.end());
    cout << res;
}
void solve(int id){
	// brute();
    cin >> n;
    for(int i = 0; i < n; i++) s += "9";
    cur = n;
    memset(memo, -1, sizeof memo);
    int128 ans = dp(0, 0, 0);
    if(n == 1) return print(ans), void();

    s = "";
    for(int i = 0; i < n - 1; i++) s += "9";
    memset(memo, -1, sizeof memo);
	cur = n - 1;
	ans = ans - dp(0, 0, 0);
	print(ans);
}

void sol(int id) {
    cin >> n;
    string ans = "9";
    for(int i = 1; i < n; i++) ans += "0";
    cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		// for(int t = 1; t <= tt; t++) solve(t);
        sol(1);
	}
}