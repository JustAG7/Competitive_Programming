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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	map<ll, vector<ll>> mp;
	for(auto &x : a) {
		cin >> x;
		mp[x % k].pb(x);
	}
	ll ans = 0, cnt = 0;
	for(auto &[_, p] : mp) {
		sort(all(p));
		int m = p.size();
		if(m % 2 != 0) {
			cnt++;
			if(cnt > 1) break;
			
			vector<ll> pre(m), suf(m);
			for(int i = 1; i < m; i += 2) {
				pre[i] = (i - 2 >= 0 ? pre[i - 2] : 0) + p[i] - p[i - 1];
			}

			for(int i = m - 2; i >= 0; i -= 2) {
				suf[i] = (i + 2 < m ? suf[i + 2] : 0) + p[i + 1] - p[i];
			}

			ll mn = inf;
			for(int i = 0; i < m; i += 2) {
				ll sum = 0;
				if(i - 1 >= 0) sum += pre[i - 1];
				if(i + 1 < m) sum += suf[i + 1];
				mn = min(mn, sum);
			}
			ans += mn / k;
		}
		else {
			for(int i = 0; i < m; i += 2) {
				ans += (p[i + 1] - p[i]) / k; 
			}
		}
	}
	cout << (cnt > 1 ? -1 : ans) << nl;
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