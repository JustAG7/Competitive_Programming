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
const int N = 1e3+5;
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
ll t[N], y[N], z[N];
ll mx, n;

ll calc(int i, ll time){
	ll sum = 0;
	ll tmp = t[i] * z[i] + y[i];
	ll remain = time % tmp;
	sum += z[i] * (time / tmp);
	if(remain >= t[i] * z[i]) sum += z[i];
	else sum += remain / t[i];
	return sum;
}
void solve(){
	cin >> mx >> n;
	for(int i=1;i<=n;i++){
		cin >> t[i] >> z[i] >> y[i];
	}
	ll l = -1, r = 2e9+1, ans = 1e10;
	while(l <= r){
		ll m = (l + r)/2;
		ll sum = 0;
		for(int i=1;i<=n;i++){
			sum += calc(i, m);
			if(sum >= mx) break;
		}
		if(sum >= mx){
			ans = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	cout << ans << nl;
	for(int i=1;i<=n;i++){
		ll cnt = calc(i, ans);
		ll res = min(mx, cnt);
		cout << res << ' ';
		mx -= res;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}