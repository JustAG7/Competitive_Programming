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
const int N = 1e5+5;
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
ll x[N], y[N];
ll preX[N], preY[N];
ll n;
ll calc(ll a, ll b) {
	ll ans = 0;
	ll pos;
	pos = upper_bound(x + 1, x + 1 + n, a) - x - 1;
	// cout << pos << ' ';
	ans += a * pos - preX[pos];
	ans += preX[n] - preX[pos] - (n - pos) * a;
	pos = upper_bound(y + 1, y + 1 + n, b) - y - 1;
	// cout << pos << nl;
	ans += b * pos - preY[pos];
	ans += preY[n] - preY[pos] - (n - pos) * b;
	return ans;
}
void solve(int id){
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> x[i] >> y[i];
	sort(x + 1, x + 1 + n);
	sort(y + 1, y + 1 + n);
	for(int i = 1; i <= n; i++) {
		preX[i] = preX[i - 1] + x[i];
		preY[i] = preY[i - 1] + y[i];
	}
	int q;
	cin >> q;
	while(q--) {
		ll a, b;
		cin >> a >> b;
		cout << calc(a, b) * 2 << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}