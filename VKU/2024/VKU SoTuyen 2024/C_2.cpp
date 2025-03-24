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
ll a[N], b[N];
int n;
bool check(ll x){
	for(int i=1;i<=n;i++) b[i] = a[i];
	b[1] -= x; // left most
	for(int i=2;i<=n;i++){
		if(a[i] < b[i - 1]) b[i] = min(b[i - 1] + 1, b[i] + x);
		else if(b[i - 1] + 1 <= b[i] + x){
			b[i] = max(b[i - 1] + 1, b[i] - x);
		}
	}
	for(int i=1;i<n;i++) if(b[i] >= b[i + 1]) return false;
	return true;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	ll l = 0, r = 1e18, ans = 0;
	while(l <= r){
		ll m = (l + r) / 2;
		if(check(m)) {
			ans = m;
			r = m - 1;
		} 
		else l = m + 1;
	}
	check(ans);
	cout << ans << nl;
	for(int i=1;i<=n;i++) cout << b[i] << ' ';

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}