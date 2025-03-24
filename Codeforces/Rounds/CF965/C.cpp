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

void solve(){
	ll n, k;
	cin >> n >> k;
	vector<pair<ll,ll>> a(n);
	for(auto &[x, y] : a) cin >> x;
	for(auto &[x, y] : a) cin >> y;
	sort(all(a));
	ll ans = 0;
	for(int i=0;i<n;i++){
		if(a[i].Y == 1){
			ll med = 0;
			if(i < n / 2) med = a[n / 2].X;
			else med = a[(n - 2) / 2].X;
			ans = max(ans, a[i].X + med + k);
		}
	}
	ll l = 0, r = 2e9;
	while(l != r){
		ll m = (l + r + 1)/2;
		int cnt = 0;
		vector<ll> res;
		for(int i=n-2;i>=0;i--){
			if(a[i].X >= m) cnt++;
			else if(a[i].Y == 1){
				res.pb(m - a[i].X);
			}
		}
		ll tmp = k;
		for(auto x : res){
			if(tmp >= x){
				tmp -= x;
				cnt++;
			}
			else break;
		}
		if(cnt >= (n + 1) / 2) l = m;
		else r = m - 1;
	}
	ans = max(ans, a[n - 1].X + l);
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}