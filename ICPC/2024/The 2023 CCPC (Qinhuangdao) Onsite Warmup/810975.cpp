#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
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


const int M = 998244353;
const int N = 1e5+5;
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
ll fact[N], inv_fact[N];
void add(ll &a, ll b){
	a += b;
	if(a >= M) a -= M;
	if(a < 0) a += M;
}
ll pm(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
	}
	return ans;
}
ll C(ll n, ll k){
	return (fact[n] * ((inv_fact[k] * inv_fact[n - k]) % M)) % M;
}
ll calc(ll n, ll m, ll k){
	ll ans = 0;
	for(int i = 1;i * k <= m && i <= n - m + 1;i++){
		ll tmp = (C(n - m + 1, i) * C(n - i * k, n - m)) % M;
		if(i & 1) add(ans, tmp);
		else add(ans, -tmp);
	}
	return ans;
}
void solve(){
	fact[0] = inv_fact[0] = 1;
	for(ll i=1;i<=N-5;i++){
		fact[i] = (fact[i - 1] * i) % M;
		inv_fact[i] = pm(fact[i], M - 2);
	}
	ll n, m, k;
	cin >> n >> m >> k;
	ll ans = calc(n, m, k);
	add(ans, -calc(n, m, k + 1));
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}

