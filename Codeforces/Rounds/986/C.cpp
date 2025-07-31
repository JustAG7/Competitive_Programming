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
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(int id){
	int n, m, v;
	cin >> n >> m >> v;
	ll sum = 0;
	vector<ll> a(n + 1, 0), pre(n + 1, 0), suf(n + 2, 0), prefsum(n + 1, 0);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
		pre[i] = pre[i - 1];
		prefsum[i] = prefsum[i - 1] + a[i];
		if(sum >= v) {
			pre[i]++;
			sum = 0;
		}
	}
	sum = 0;
	for(int i = n; i >= 1; i--) {
		sum += a[i];
		suf[i] = suf[i + 1];
		if(sum >= v) {
			sum = 0;
			suf[i]++;
		}
	}
	ll ans = 0;
	if(pre[n] - pre[0] < m) return cout << "-1\n", void();
	for(int l = 1, r = 1; r <= n; r++) {
		while(pre[l - 1] + suf[r + 1] < m && l <= r) l++;
		ans = max(ans, prefsum[r] - prefsum[l - 1]);
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}