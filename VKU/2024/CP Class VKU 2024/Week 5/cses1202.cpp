#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
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
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int n, m;
vector<pair<int,int>> g[N];
ll f[N], fmn[N], fmx[N], cnt[N];
void solve(){
	cin >> n >> m;
	for(int i=0;i<m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb({v, w});
	} 
	memset(f, 0x3f, sizeof f);
	memset(fmn, 0x3f, sizeof fmn);
	
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push({0, 1});
	f[1] = 0;
	cnt[1] = 1;
	fmn[1] = 0;
	fmx[1] = 0;

	while(pq.size()) {
		auto [val, u] = pq.top();pq.pop();
		if(f[u] != val) continue;
		for(auto [v, w] : g[u]) {
			if(val + w == f[v]) {
				cnt[v] = (cnt[u] + cnt[v]) % M;
				fmn[v] = min(fmn[v], fmn[u] + 1);
				fmx[v] = max(fmx[v], fmx[u] + 1);
			}
			else if(val + w < f[v]) {
				cnt[v] = cnt[u];
				fmn[v] = fmn[u] + 1;
				fmx[v] = fmx[u] + 1;
				f[v] = val + w;
				pq.push({f[v], v});
			}
		}
	}
	cout << f[n] << ' ' << cnt[n] << ' ' << fmn[n] << ' ' << fmx[n];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}