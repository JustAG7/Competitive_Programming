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

vector<vector<int>> cols, rows;
char a[1005][1005];
ll pm(ll a, ll b){
	ll ans = 1;
	while(b){
		if(b&1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		int cnt = 0; vector<int> res;
		for(int j=1;j<=n;j++){
			if(a[i][j] == '#') cnt++;
			else {
				if(cnt > 0) res.pb(cnt);
				cnt = 0;
			}
		}
		if(cnt > 0) res.pb(cnt);
		rows.pb(res);
	}
	for(int i=1;i<=n;i++){
		int cnt = 0; vector<int> res;
		for(int j=1;j<=n;j++){
			if(a[j][i] == '#') cnt++;
			else {
				if(cnt > 0) res.pb(cnt);
				cnt = 0;
			}
		}
		if(cnt > 0) res.pb(cnt);
		cols.pb(res);
	}
	ll row = 0, col = 0;
	for(auto s : rows){
		ll tmp = 0;

		for(auto x : s){
			ll y = x;
			tmp += pm(y, y);
			tmp %= M;
		}
		row = max(row, tmp);
	}

	for(auto s : cols){
		ll tmp = 0;

		for(auto x : s){
			ll y = x;
			tmp += pm(y, y);
			tmp %= M;
		}
		col = max(col, tmp);
	}
	cout << row << ' ' << col;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}