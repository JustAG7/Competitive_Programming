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
const int N = 1e5;
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
ll fact[N + 5], inv_fact[N + 5];
ll cnt[6];
ll n, m;
ll pm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return ans;
}
void process() { 
	fact[0] = 1;
	for(int i = 1; i <= 1000; i++) {
		fact[i] = (fact[i - 1] * i) % M;
	}
}
ll calc(int cnt4, int cnt6) {
	ll ans = fact[n];
	vector<int> f(7, 0);
	f[2] = cnt[2] - cnt4 * 2 - cnt6;
	f[3] = cnt[3] - cnt6;
	f[4] = cnt4;
	f[5] = cnt[5];
	f[6] = cnt6;
	int sum = 0;
	ll deno = 1; // 4, 6
	for(int i = 2; i <= 6; i++) {
		deno = (deno * fact[f[i]]) % M;
		sum += f[i];
		// cout << f[i] << ' ';
	}
	if(sum > n) return 0;
	deno = (deno * fact[n - sum]) % M;
	// cout << f[1] << nl;
	return (ans * pm(deno, M - 2)) % M;
}
void solve(int id){
	cin >> n >> m;
	for(auto i : {2, 3, 5}) {
		while(m % i == 0 && m >= i) {
			cnt[i]++;
			m /= i;
		}
	}
	ll ans = 0;
	if(m > 1) return cout << 0, void();
	for(int i = 0; i <= cnt[2] / 2; i++) {
		for(int j = 0; j <= min(cnt[2], cnt[3]); j++) {
			if(i * 2 + j > cnt[2]) continue;
			ans += calc(i, j);
			ans %= M;	
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}