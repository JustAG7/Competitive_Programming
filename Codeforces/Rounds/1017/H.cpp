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

vector<int> f[N];

void process() {
	for(int i = 2; i <= N - 5; i++) {
		for(int j = i; j <= N - 5; j += i) {
			f[j].pb(i);
		}
	}
}
void solve(int id){
	int n, q;
	cin >> n >> q;
	map<int, vector<int>> mp;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]].pb(i);
	}
	while(q--) {
		ll k, l, r;
		cin >> k >> l >> r;
		ll ans = 0;
		while(k > 1 && l <= r) {
			ll mx = r + 1;
			for(auto p : f[k]) {
				auto it = lower_bound(all(mp[p]), l);
				if(it == mp[p].end() || *it > r) continue;
				mx = min(mx, (ll)*it);
			}
			ans += (mx - l) * k;
			if(mx <= r) {
				while(k % a[mx] == 0) k /= a[mx];
				ans += k;
			}
			l = mx + 1;
		}
		if(k == 1 && l <= r) ans += (r - l + 1);
		cout << ans << nl;
	}
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}