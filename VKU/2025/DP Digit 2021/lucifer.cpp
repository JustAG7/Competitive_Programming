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

ll memo[10][105][105][2];


string s;

bool check(int n) {
	if(n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}


ll dp(int pos, int sumOdd, int sumEven, bool under) {
	if(pos == s.size()) {
		return check(sumEven - sumOdd);
	}

	ll &ans = memo[pos][sumOdd][sumEven][under];
	if(ans != -1) return ans;

	ans = 0;
	int lim = under ? 9 : s[pos] - '0';

	for(int i = 0; i <= lim; i++) {
		if(pos % 2 == 0) ans += dp(pos + 1, sumOdd, sumEven + i, under || (i < lim));
		else ans += dp(pos + 1, sumOdd + i, sumEven, under || (i < lim));
	}

	return ans;
}
void solve(int id){
	
	ll a, b;
	cin >> a >> b;;

	s = to_string(b);
	if((int)s.size() % 2 != 0) s = "0" + s;
	memset(memo, -1, sizeof memo);
	ll ans = dp(0, 0, 0, 0);

	s = to_string(a - 1);
	if((int)s.size() % 2 != 0) s = "0" + s;
	memset(memo, -1, sizeof memo);
	cout << ans - dp(0, 0, 0, 0);
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