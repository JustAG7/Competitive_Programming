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
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
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

ll find(int x, int y, ll n) {
	if(n == 1) {
		if(x == 1 && y == 1) return 1;
		if(x == 2 && y == 2) return 2;
		if(x == 2 && y == 1) return 3;
		return 4;
	}
	// cerr << x << ' ' << y << ' ' << n << nl;
	int bound = 1 << (n - 1);

	// (2^n) / 2 * (2^n) / 2
	// 2^(n - 1) * 2^(n - 1)
	// 2^((n - 1) + (n - 1))  wtf with this?
	// 2 ^ (2 * (n - 1))

	ll res = 1LL << ((n - 1) * 2LL);
	// cerr << res << nl;

	// top left
	if(x <= bound && y <= bound) return find(x, y, n - 1);
	// bottom right
	if(x > bound && y > bound) return res + find(x - bound, y - bound, n - 1);
	// bottom left
	if(x > bound && y <= bound) return 2LL * res + find(x - bound, y, n - 1);
	// top right
	return 3LL * res + find(x, y - bound, n - 1);
}

pair<int, int> locate(ll x, int n) {
	if(n == 1) {
		if(x == 1) return {1, 1};
		if(x == 2) return {2, 2};
		if(x == 3) return {2, 1};
		else return {1, 2};
	}

	int bound = 1 << (n - 1);
	ll res = 1LL << ((n - 1) * 2LL);

	// cerr << res << nl;
	// top left
	if(x <= res) {
		auto location = locate(x, n - 1);
		// cerr << n << ' ' << location.first << ' ' << location.second << nl;
		return {location.first, location.second};
	}

	// bottom right
	if(x <= 2LL * res) {
		auto location = locate(x - res, n - 1);
		// cerr << n << ' ' << location.first << ' ' << location.second << nl;
		return {location.first + bound, location.second + bound};
	}

	// bottom left
	if(x <= 3ll * res) {
		auto location = locate(x - 2LL * res, n - 1);
		// cerr << n << ' ' << location.first << ' ' << location.second << nl;
		return {location.first + bound, location.second};
	}

	// top right

	auto location = locate(x - 3LL * res, n - 1);
	// cerr << n << ' ' << location.first << ' ' << location.second << nl;
	return {location.first, location.second + bound};
}
void solve(int id){
	ll n, q;
	cin >> n;
	cin >> q;
	while(q--) {
		string s; cin >> s;
		if(s == "->") {
			int x, y; cin >> x >> y;
			cout << find(x, y, n) << nl;
		}
		else {
			ll x; cin >> x;
			auto location = locate(x, n);
			cout << location.first << ' ' << location.second << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}