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


const int M = 1e9+7;
const int N = 4e4+5;
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

int a[N], b[N], last[N];
int cnt[N];
int dp[N][55];
int diff, cl, cr;

void add(int idx) {
    if (cnt[a[idx]] == 0) diff++;
    cnt[a[idx]]++;
}

void remove(int idx) {
    cnt[a[idx]]--;
    if (cnt[a[idx]] == 0) diff--;
}

int calc_diff(int L, int R) {
    while (cr < R) add(++cr);
    while (cl > L) add(--cl);
    while (cr > R) remove(cr--);
    while (cl < L) remove(cl++);
    return diff;
}

void calc(int l, int r, int u, int v, int p) {
	if (l > r) return;

    int m = (l + r) / 2;
    int res = -1;
    int ans = -1;

    for (int k = u; k <= min(m, v); k++) {
        int cost = dp[k][p - 1] + calc_diff(k + 1, m);
        if (cost > ans) {
            ans = cost;
            res = k;
        }
    }

	dp[m][p] = ans;
	calc(l, m - 1, u, res, p);
	calc(m + 1, r, res, v, p);
}
void solve(int id){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	// for(int i = 1; i <= n; i++) cout << b[i] << ' '; cout << nl;
	for(int i = 1; i <= k; i++) {
		calc(i, n, i - 1, n - 1, i);
	}
	cout << dp[n][k];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}