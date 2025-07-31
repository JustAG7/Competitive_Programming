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

bool cmp(array<int, 3> &a, array<int, 3> &b) {
	if(a[0] == b[0]) return a[1] < b[1];
	return a[0] < b[0];
}

int ans[N];
pair<int, int> a[N];
void solve(int id){
	int n, m;
	cin >> m >> n;
	vector<int> free;
	vector<array<int, 3>> query; 
	for(int i = 1; i <= m; i++) free.pb(i);
	for(int i = 1; i <= n; i++) {
		int s, f; cin >> s >> f;
		a[i] = {s, f};
		query.pb({s, 1, i});
		query.pb({f, -1, i});
	}
	sort(all(query), cmp);
	set<pair<int, int>> s;
	int cur = 0;
	for(auto [time, type, id] : query) {
		if(type == 1) {
			if(free.size()) {
				int dock = free.back(); free.pop_back();
				ans[id] = dock;
				cur++;
				s.insert({a[id].second, id});
			}
			else {
				auto it = --s.end();
				auto [finish, prev_id] = *it;
				finish = -finish;

				if(time < finish) {
					ans[id] = ans[prev_id];
					s.erase(it);

					s.insert({time, id});
					ans[prev_id] = 0;

				}
			}
		}
		else {
			int dock = ans[id];
			free.pb(dock);

			s.erase({a[id].second, id});
		}
	}
	cout << cur << nl;
	for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}