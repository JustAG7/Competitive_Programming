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


const int M = 998244353;
const int N = 3e3+5;
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

pair<ll,ll> a[N];

void add(ll &a, ll b) {
	a += b;
	a += M;
	a %= M;
}

ll pm(ll a, ll b) {
	ll ans = 1;
	for(int i = 0; i < b; i++) {
		ans = (ans * a) % M;
	}
	return ans;
}

int getD(ii x, ii y, ii z) {
	int ans = 1;
	if(x.second != y.second) ans++;
	if(x.second != z.second && y.second != z.second) ans++;
	return ans;
}

bool check(ii a, ii b, ii c) {
	return a.first + b.first > c.first;
}
void solve(int id){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	ll ans = 0;

	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n - 2; i++) {
		for(int j = i + 1; j <= n - 1; j++) {
			for(int k = j + 1; k <= n; k++) {
				if(!check(a[i], a[j], a[k])) continue;
				ll sum = (a[i].first + a[j].first + a[k].first) % M;
				add(ans, pm(sum, getD(a[i], a[j], a[k])));
				cerr << i << ' ' << j << ' ' << k << nl;
				cerr << ans << nl;
			}
		}
	}
	cout << ans;
}

int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}