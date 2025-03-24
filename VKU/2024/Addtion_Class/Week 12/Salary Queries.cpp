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
const int N = 4e5+5;
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

vector<array<int, 3>> query;
vector<int> res;
int a[N], bit[N];
void upd(int u,int val){
	for(; u <= N; u += u & -u){
		bit[u] += val;
	}
}
void add(int x,int val){
	int pos = upper_bound(all(res), x) - res.begin();
	upd(pos, val);
}
int get(int u){
	int ans = 0;
	for(; u > 0; u -= u & -u){
		ans += bit[u];
	}
	return ans;
}
int getRange(int x){
	int pos = upper_bound(all(res), x) - res.begin();
	return get(pos);
}
void solve(){
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		res.pb(a[i]);
	}

	for(int i=0;i<q;i++){
		char t;int a, b;
		cin >> t >> a >> b;
		query.pb({t == '?', a, b});
		if(t == '!') res.pb(b);
	}
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	for(int i=1;i<=n;i++) add(a[i], 1);
	
	for(auto q : query){
		if(q[0] == 0){
			add(a[q[1]], -1);
			a[q[1]] = q[2];
			add(a[q[1]], 1);
		}
		else cout << getRange(q[2]) - getRange(q[1] - 1) << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}