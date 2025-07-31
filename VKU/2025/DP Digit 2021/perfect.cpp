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

ll memo[20][60][37][25][20];
ll p10[20];

string s;
ll lim, cur;
ll a, b, l, r;
void get(int x, int &c2, int &c3, int &c5, int &c7) {
	if(x <= 1) return;
	while(x % 2 == 0) c2--, x /= 2;
	while(x % 3 == 0) c3--, x /= 3;
	while(x % 5 == 0) c5--, x /= 5;
	while(x % 7 == 0) c7--, x /= 7;
}
ll dp(int pos, ll num, int c2, int c3, int c5, int c7) {
	if(c2 < 0 || c3 < 0 || c5 < 0 || c7 < 0) return 0;
	if(pos == 0) {
		return (c2 + c3 + c5 + c7 == 0) && (l <= num && num <= r);
	}

	ll mn = num * p10[pos];
	ll mx = mn + p10[pos] - 1;

	if(mx < l || r < mn) return 0;
	bool ok = (l <= mn && mx <= r);
	ll ans = memo[pos][c2][c3][c5][c7];
	if(ok && ans != -1) return ans;

	ans = 0;

	if(num == 0) ans += dp(pos - 1, num, c2, c3, c5, c7);
	for(int i = 1; i <= 9; i++) {
		int n2 = c2, n3 = c3, n5 = c5, n7 = c7;
		get(i, n2, n3, n5, n7);
		ans += dp(pos - 1, num * 10 + i, n2, n3, n5, n7);
	}
	
	if(ok) memo[pos][c2][c3][c5][c7] = ans;
	return ans;
}

ll calc(ll num, int c2, int c3, int c5, int c7) {
	if(num > lim) return 0;
	l = (a + num - 1) / num;
	r = b / num;
	ll ans = dp(18, 0, c2, c3, c5, c7);

	if(!c3 && !c5 && !c7) ans += calc(num * 2, c2 + 1, c3, c5, c7);
	if(!c5 && !c7) ans += calc(num * 3, c2, c3 + 1, c5, c7);
	if(!c7) ans += calc(num * 5, c2, c3, c5 + 1, c7);
	ans += calc(num * 7, c2, c3, c5, c7 + 1);

	return ans;

}
void solve(int id){
	cin >> a >> b;

	lim = sqrt(b);

	memset(memo, -1, sizeof memo);
	ll ans = calc(1, 0, 0, 0, 0);
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	p10[0] = 1;
	for(int i = 1; i <= 18; i++) p10[i] = p10[i - 1] * 10;
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}