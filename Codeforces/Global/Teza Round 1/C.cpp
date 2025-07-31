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

void solve(int id){
	int n;
	cin >> n;
	vector<int> a(n + 1), b(n + 1), pos(n + 1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}
	for(int i = 1; i <= n; i++) cin >> b[i];
	bool ok = true;
	int cnt = 0, mark = 0;
	vector<pair<int,int>> ans;
	auto exchange = [&](int x, int y) -> void {
		if(x == y) return;
		ans.pb({x, y});
		swap(a[x], a[y]);
		swap(pos[a[x]], pos[a[y]]);
		swap(b[x], b[y]);
	};
	for(int i = 1; i <= n; i++) {
		if(a[i] == b[i]) {
			cnt++;
			mark = i;
		}
		else if(b[pos[b[i]]] != a[i]) ok = false; // suppose 2 3 => should be palindromic
												  //         3 2
	}
	if(!ok || (n % 2 == 0 && cnt > 0) || (n % 2 != 0 && cnt != 1)) return cout << "-1\n", void();
	if(n % 2 != 0) exchange(mark, (n + 1) / 2);
	for(int i = 1; i <= n / 2; i++) {
		exchange(pos[b[i]], n - i + 1);
	}
	cout << ans.size() << nl;
	for(auto [x, y] : ans) cout << x << ' ' << y << nl;

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