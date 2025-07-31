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


const int M = 1e9+7;
const int N = 2e5+5;
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
ll fact[N];
void process(){
	fact[0] = 1;
	for(int i=1;i<=N-5;i++){
		fact[i] = fact[i - 1] * i;
		fact[i] %= M;
	}
}
ll pm(ll a, ll b){
	ll ans = 1;
	while(b > 0){
		if(b&1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
	}
	return ans;
}
ll C(ll n, ll k){
	// n! / (k! * (n - k)!)
	// a / b % c = a % M * b^-1
	ll x = fact[n];
	ll y = (fact[k] * fact[n - k]) % M;
	return (x * pm(y, M - 2)) % M;
}
void solve(){
	int n, k;
	cin >> n >> k;
	vector<ll> a(n + 1), b(2, 0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[a[i]]++;
	}
	ll ans = 0;
	for(int x=0;x<=b[0];x++){
		int y = k - x;
		if(0 <= y && y <= b[1]){
			if(y > x) ans += C(b[0], x) % M * C(b[1], y) % M;
			ans %= M;
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}