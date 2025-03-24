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
	ll ans = inf;
	ll l = k, r = k + n - 1;
	auto calc = [&](ll a, ll b) -> ll {
		ll sumA = a * (a + 1) / 2;
		ll sumB = b * (b + 1) / 2;
		return sumA - sumB;
	};
	while(l <= r){
		ll m = (l + r) / 2;
		ll a = calc(m, k - 1), b = calc(k + n - 1, m);
		if(a < b) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	ll a = calc(k + n - 1, ans) - calc(ans, k - 1);
	ll b = calc(ans + 1, k - 1) - calc(k + n - 1, ans + 1);
	cout << min(a, b) << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}