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
const int N = 2e3+5;
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

int dp[N][N];

int a[N], b[N], c[N];

template<class T>
	struct Compressor {
		vector<T> res;

		int getsz() {
			return res.size();
		}

		void add(T x) {
			res.pb(x);
		}

		void compress() {
			sort(all(res));
			res.erase(unique(all(res)), res.end());
		}

		T find(T x) {
			return lower_bound(all(res), x) - res.begin() + 1;
		}
	};


struct Fenwick {
    vector<int> t;
    int n;

    void init(int _n) {
        n = _n;
        t.assign(n + 2, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            t[idx] = max(t[idx], val);
            idx += idx & -idx;
        }
    }

    int get(int idx) {
        int res = 0;
        while (idx > 0) {
            res = max(res, t[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
};

void solve(int id){
	int n, m; cin >> n >> m;
	
	Compressor<ll> cp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		cin >> b[i];
		cp.add(b[i]);
		cp.add(b[i] / 2);
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) dp[i][j] = 0;
	cp.compress();

	int k = cp.getsz();

	int ans = 0;

    for (int i = 1; i <= n; i++) {
        Fenwick st;
        st.init(k);

        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j]; 

            if (a[i] == b[j]) {
                int pos = cp.find(b[j] / 2);
                int res = st.get(pos);

                dp[i][j] = max(dp[i][j], res + 1);
                ans = max(ans, dp[i][j]);
            }

            int pos = cp.find(b[j]);
            st.update(pos, dp[i - 1][j]);
        }
    }

    cout << ans << nl;
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