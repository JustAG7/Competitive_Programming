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
	int n;
	cin >> n;
	map<int,int> x1, x0;
	ll ans = 0, cnt0 = 0, cnt1 = 0;
	for(int x, y, i = 1; i <= n; i++){
		cin >> x >> y;
		if(y == 0) {
			x0[x]++;
			cnt0++;
		}
		else {
			x1[x]++;
			cnt1++;
		}
	}
	cnt0--, cnt1--;
	for(int i=0;i<=n;i++) {
		if(x1[i] && x0[i]) ans += cnt0 + cnt1;
		if(x1[i] && x0[i - 1] && x0[i + 1]) ans++;
		if(x0[i] && x1[i - 1] && x1[i + 1]) ans++;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}