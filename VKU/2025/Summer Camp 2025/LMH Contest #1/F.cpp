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
const int N = 1e6+5;
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
const int LOG = 21;

int t[N], a[N];
int st[N][LOG];
int f[N];

void RMQ(int n) {
	for(int i = 1; i <= n; i++) {
		st[i][0] = f[i];
	}

	for(int j = 1; (1 << j) <= n; j++) {
		for(int i = 1; i + (1 << j) - 1 <= n; i++) {
        	st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int l, int r) {
	int j = log2(r - l + 1);
	return min(st[l][j], st[r - (1 << j) + 1][j]);
}

void solve(int id){
	string s; cin >> s;
	int n = s.size();
	for(int i = 1; i <= n; i++) a[i] = (s[i - 1] == 'T');
	for(int i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];
	for(int i = 1; i <= 2 * n; i++) {
		t[i] = t[i - 1] + a[i];
		f[i] = 2 * t[i] - i;
	}

	RMQ(2 * n);
	
	int ans = M;
	for(int i = 1; i <= n; i++) {
		int l = i, r = i + n;
		int cost = i + n - t[i] - t[i + n];
		int f = query(l, r);
		ans = min(ans, cost + f);
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}