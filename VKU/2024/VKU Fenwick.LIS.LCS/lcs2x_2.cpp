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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}


struct Fenwick {
	int f[N], n;
	void init(int _n) {
		n = _n;
		fill(f, f + n + 5, M);	
	}
	void update(int u, int val) {
		for(; u <= n; u += (u & (-u))) {
			f[u] = min(f[u], val);
		}
	}
	int get(int u) {
		int ans = 0;
		for(; u > 0; u -= (u & (-u))) {
			ans = min(f[u], ans);
		}
		return ans;
	}
};
int getPos(int val, vector<int> &res) {
	int ans = -1, l = 1, r = res.size() - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(res[m] <= val) {
			ans = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	return ans;
}
void solve(int id){
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	vector<int> c;
	map<int, int> mp;
	Fenwick BIT;
	c.pb(-1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]] = i;
		c.pb(a[i]);
	}
	sort(all(c));
	c.erase(unique(all(c)), c.end());
	n = c.size() - 1;
	BIT.init(n);
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int x; cin >> x;
		if(!mp[x]) continue;
		int res = 0;
		int pos = getPos(x / 2, c);
		res = max(res, BIT.get(pos));
		// if(id == 1) {
		// 	cerr << x << ' ' << pos;
		// 	cerr << ' ' << res << ' ' << getPos(x, c) << nl;
		// }
		BIT.update(getPos(x, c), res + 1);
		ans = max(ans, res + 1);

	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}