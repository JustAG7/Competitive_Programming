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
           

const int M = 1e9+7;
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

const int N = 5e4 + 5;
ll a[N];
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
			int pos = lower_bound(all(res), x) - res.begin() + 1;
			if(res[pos - 1] != x) return pos - 1;
			return pos; 
		}
	};


struct Fenwick {
    vector<int> t;
    int n;

    void init(int _n) {
        n = _n;
        t.assign(n + 2, M);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            t[idx] = min(t[idx], val);
            idx += idx & -idx;
        }
    }

    int get(int idx) {
        int res = M;
        while (idx > 0) {
            res = min(res, t[idx]);
            idx -= idx & -idx;
        }
        return res;
    }
} fenwick;
void solve(int id){
	int n;
	cin >> n;
	Compressor<ll> cp;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		cp.add(a[i]);
	}

	cp.compress();
	int k = cp.getsz();
	fenwick.init(k);


	for(int i = 1; i <= n; i++) {
		int pos = cp.find(a[i]);
		fenwick.update(pos, i);
	}
	
	int q; cin >> q;
	while(q--) {
		ll x; cin >> x;
		while(1) {
			int pos = cp.find(x);
			if(pos == 0) break;
			if(pos > k) pos = k;

			pos = fenwick.get(pos);
			x %= a[pos];
		}
		
		cout << x << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	// time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	// }
}