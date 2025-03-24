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


const int M = 1e9+7;
const int N = 1e6+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

int n;
vector<int> w;
vector<int> a;
vector<int> b;
vector<int> adj[N];
bool ok[N] = {0};
vector<int> group;
vector<int> edx_max;
void dfs(int u) {
	if(ok[u] == 0) {
		group.push_back(u);
		ok[u] = 1;
	}
	for(int v : adj[u]) {
		if(ok[v]) continue;
		edx_max.push_back(w[u] + w[v]);
		dfs(v);
	}
}
void ip() {
	cin >> n;
	w.push_back(0);
	a.push_back(0);
	b.push_back(0);
	for(int i = 1; i <= n; ++i) {
		int ai; cin >> ai;
		w.push_back(ai);
	}
	for(int i = 1; i <= n; ++i) {
		int ai; cin >> ai;
		a.push_back(ai);
	}
	for(int i = 1; i <= n; ++i) {
		int ai; cin >> ai;
		b.push_back(ai);
	}
	for(int i = 1; i <= n; ++i) {
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
}
void solve(int id){
	ip();
	ll res = 0;
	for(int u = 1; u <= n; ++u) {
		if(ok[u]) continue;
		group.clear();
		edx_max.clear();
		dfs(u);
		vector<int> val;
		for(int gi: group) {
			val.push_back(w[gi]);
		}
		sort(all(val));
		sort(all(edx_max));
		if(edx_max.size() > 1)
		for(int i = 0; i < edx_max.size()-1; ++i) {
			res += edx_max[i];
		}
	}
	cout << res; 
}

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}