#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define int long long
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
const ll n6 = 166666668;
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
ll n, x, k;
ll a[N], cnt[N];

// generally: a[i] = (i + n*k)^2 = i^2 + 2 * i * n * k + (n*k)^2
// a[i] += i^2 * k + i * n * k * (k - 1) + n^2 * (k - 1) * (k) * (2k - 1)/ 6


ll add(ll a, ll b, ll c){
	return (a + b + c) % M;
}

ll calc1(ll i, int index){
	return ((i * i) % M * (cnt[index]) % M) % M;
}
ll calc2(ll i, int index){
	return (((i * n) % M) * (cnt[index] * (cnt[index] - 1)) % M) % M;
}
ll calc3(ll i, int index){
	ll tmp = cnt[index];
	return ((((n * n) % M) * ((tmp * (tmp - 1)) % M)) % M) * (((2 * tmp - 1) * n6) % M) % M;
}
ll ans[N];
void solve(){
	cin >> n >> x >> k;
	ll count = k / n;
	ll remain = k - count*n;
	ll curr = x;
	for (int i = 1; i <= n; i++) cnt[i] = count;
    
    for (int i = x; i < x + remain; i++) {
        cnt[(i - 1) % n + 1]++;

    }
    // dbgArr(cnt, n + 1);
    for (ll curr = 1, i = x; curr <= n; i++, curr++) {
        ans[i] = add(calc1(curr, i), calc2(curr, i), calc3(curr, i));
        if (i == n) i = 0;
    }
    for (int i = 1; i <= n; i++) cout << ans[i] % M << ' ';
    cout << nl;
}
signed main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}