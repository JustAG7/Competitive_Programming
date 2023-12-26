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
ll a[205], pref[205];
ll minMoney[205][205];
ll x,y;
int n;
ll dp(int l,int r){
	if(l > r) return inf;
	if(minMoney[l][r]) return minMoney[l][r];
	ll money = x + y - pref[l - 1] - (pref[n] - pref[r]);
	
	ll res = inf;

	ll goLeft = max(a[l], money - dp(l + 1, r) + 1);

	ll goRight = max(a[r], money - dp(l, r - 1) + 1);
	res = min({res, goLeft, goRight}); 

	return minMoney[l][r] = res;
}
void solve(){
	cin >> n >> x >> y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) minMoney[i][j] = 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	cout << (x >= dp(1, n) ? "Haros\n" : "Iwys\n");
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
} 