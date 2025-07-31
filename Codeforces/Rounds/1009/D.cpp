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
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(int id){
	int n, m;
	cin >> n >> m;
	// cerr << "test " << id << ": \n";
	vector<ll> x(n), r(n);
	for(ll &c : x) cin >> c;
	for(ll &c : r) cin >> c;
	ll ans = 0;
	map<ll, ll> mp;
	auto get = [&](ll n) {
		ll tmp = sqrt(n + 5);
		while(tmp * tmp > n) tmp--;
		return tmp;
	};
	for(int i = 0; i < n; i++) {
		for(int j = x[i] - r[i]; j <= x[i] + r[i]; j++) {
			ll res = r[i] * r[i] - (j - x[i]) * (j - x[i]);
			res = 2 * get(res) + 1; // |r_i - (j - x_i)|
			// cerr << 2 * res + 1 << nl;
			mp[j] = max(mp[j], res);
		}
	}
	for(auto [_, count] : mp) ans += count;
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}