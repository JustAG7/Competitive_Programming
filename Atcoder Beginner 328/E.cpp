#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll unsigned long long
#define int unsigned long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
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
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;


char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

struct Edge {
    int u,v; ll c;
    Edge(int _u, int _v, ll _c): u(_u), v(_v), c(_c) {};
};

struct Dsu {
    vector<int> par;

    void init(int n) {
        par.resize(n + 5, 0);
        for (int i = 1; i <= n; i++) par[i] = i;
    }

    int find(int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    }

    bool join(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        par[v] = u;
        return true;
    }
} dsu;

int n, m;
ll k, ans = 0;
vector<Edge> edges;

void solve(){
	cin >> n >> m >> k;

    for (int i=0;i<m;i++) {
        int u, v;
        ll c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }
    dsu.init(n);
    sort(all(edges), [](Edge &x, Edge &y) {
        return x.c < y.c;
    });
    for (auto e : edges) {
        if (!dsu.join(e.u, e.v)) continue;
        ans = (ans%k + e.c%k) % k;
    }

    cout << ans << '\n';
}
signed main() {
	fast;
	indef();
    int tt=1;
	// cin >> tt;
	while(tt--) solve();
}