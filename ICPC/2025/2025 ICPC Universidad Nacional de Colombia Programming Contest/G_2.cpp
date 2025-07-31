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

typedef long long Int;
Int r[N], x[N], last[N];
int vis[N];

inline Int dist(int i, int j) { return abs(x[i]-x[j]) - (r[i] + r[j]); }
inline Int collide_time(const Int diff) { return max(0LL, (diff + 1) / 2); }

void solve(int id){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> x[i] >> r[i];
		last[i] = 0;
	}

	set<array<Int,3>> s;
	set<int> alive;
	for (int i = 1; i <= n; i++) alive.insert(i);

	vector<Int> res;
	for(int i = 1; i < n; i++) {		
		int diff = dist(i,i+1);
		s.insert({collide_time(diff), i, i + 1});
	}

	while (alive.size() > 1) {
		auto it = s.begin();
		auto [time, i, j] = *it;
		s.erase(it);

		if (vis[i] || vis[j]) continue;
		
		assert((time >= max(last[i], last[j])));
		r[i] += time - last[i]; last[i] = time;
		r[j] += time - last[j]; last[j] = time;

		if(r[i] == r[j]) {
			if(i > j) swap(i, j);
		}
		else {
			if(r[i] < r[j]) swap(i, j);
		}
		cerr << "EVENT: " << time << ' ' << i << ' ' << j;
		cerr << "\t\t radii (before) " << r[i] << ' ' << r[j]; 
		r[i] += r[j];
		vis[j] = 1;
		alive.erase(j);
		res.pb(time);
		cerr << "\t\t radii (after) " << r[i] << ' ' << r[j] << nl; 

		{
			auto it = alive.upper_bound(i);
			if (it != end(alive)) {
				int nxt = *it;
				Int diff = dist(i, nxt);
				// if (n > 10) 
					// diff -= (time - last[nxt]);
				Int ntime = time + collide_time(diff);
				cerr << "dif " << diff; cerr << " next: " << ntime << ' ' << i << ' ' << nxt << nl;
				s.insert({ntime, i, nxt});
			}
		}

		{
			auto it = alive.lower_bound(i);
			if (it != begin(alive)) {
				--it;
				int nxt = *it;
				Int diff = dist(i, nxt);// - (time - last[i]) - (time - last[nxt]);
				// if (n > 10) 
					// diff -= (time - last[nxt]);
				Int ntime = time + collide_time(diff);
				cerr << "dif " << diff; cerr << " next: " << ntime << ' ' << i << ' ' << nxt << nl;
				s.insert({ntime, i, nxt});

			}
		}
	}
	for (auto x : res) cerr << x << ' '; cerr << nl;

	int q; cin >> q;
	while (q--) {
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
// xq cute <3