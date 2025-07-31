// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define curTime__(d) \
    for ( \
        auto blockcurTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockcurTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockcurTime.first).count()), blockcurTime.second = false \
    )


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

struct DSU {
	vector<int> par;
	int n;

	void init(int _n) {
		n = _n;
		par.assign(n + 5, 0);
		for(int i = 1; i <= n; i++) {
			par[i] = i;
		}
	}

	int find_set(int x) {
		return x == par[x] ? x : par[x] = find_set(par[x]);
	}

	bool union_set(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if(x == y) return false;
		par[y] = x;
		return true;
	}
} lft, rght;

int r[N], x[N], curTime[N];
int sz[N], vis[N];
void solve(int id){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> r[i];
		sz[i] = 1;
	}
	set<array<int, 3>> s;

	lft.init(n);
	rght.init(n);

	vector<int> res;
	for(int i = 2; i < n; i++) {
		int diff, curTime;
		
		// left
		diff = abs(x[i] - x[i - 1]) - r[i] - r[i - 1];
		curTime = max(0, diff / 2 + (diff % 2 != 0));
		
		s.insert({curTime, i, i - 1});
		// right

		diff = abs(x[i] - x[i + 1]) - r[i] - r[i + 1];
		curTime = max(0, diff / 2 + (diff % 2 != 0));
		s.insert({curTime, i, i + 1});
	}

	while(s.size() > 1) {
		auto it = s.begin();
		auto [curTime, i, j] = *it;
		s.erase(it);
		if(vis[i] || vis[j]) continue;
		if(r[i] == r[j]) {
			if(i > j) swap(i, j);
		}
		else {
			if(r[i] < r[j]) swap(i, j);
		}
		cerr << "EVENT: " << curTime << ' ' << i << ' ' << j << nl;
		cerr << "RADIUS " << r[i] << ' ' << r[j] << nl; 

		cerr << "processing \n";
		r[i] += r[j];
		if(i < j) {
			if(j < n) {
				rght.union_set(j + 1, j);
				int nxt = rght.find_set(j + 1);

				int diff = abs(x[i] - x[nxt]) - r[i] - r[nxt];
				int ncurTime = curTime + max(0, diff / 2 + (diff % 2 != 0));
				cerr << "next: " << ncurTime << ' ' << i << ' ' << nxt << nl << nl;
				s.insert({ncurTime, i, nxt});
			}

		}

		else {
			if(j > 1) {
				lft.union_set(j - 1, j);
				int nxt = lft.find_set(j - 1);

				int diff = abs(x[i] - x[nxt]) - r[i] - r[nxt];
				int ncurTime = curTime + max(0, diff / 2 + (diff % 2 != 0));
				cerr << "next: " << ncurTime << ' ' << i << ' ' << nxt << nl << nl;

				s.insert({ncurTime, i, nxt});
			}
		}
		vis[j] = 1;
		res.pb(curTime);
	}

	int q; cin >> q;
	for(auto x : res) cout << x << ' '; cout << nl;
	while(q--) {
		int x; cin >> x;
		int pos = upper_bound(all(res), x) - res.begin();
		cout << n - pos << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	curTime__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}