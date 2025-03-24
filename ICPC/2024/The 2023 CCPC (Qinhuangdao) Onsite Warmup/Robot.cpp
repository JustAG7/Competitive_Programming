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
const int N = 5e5+5;
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
int n, m, k;
string s;
struct node {
	int c[5] = {0};
};
int get(char x){
	if(x == 'U') return 1;
	if(x == 'D') return 2;
	if(x == 'L') return 3;
	return 4;
}
node st[4 * N];
void clear(){
	for(int i=0;i<4*N;i++){
		for(int j=0;j<=4;j++){
			st[i].c[j] = 0;
		}
	}
}
node combine(node a, node b){
	node ans;
	for(int i=1;i<=4;i++){
		ans.c[i] += a.c[i];
		ans.c[i] += b.c[i];
	}
	return ans;
}
void build(int id, int l, int r){
	if(l == r){
		int cur = get(s[l]);
		st[id].c[cur]++;
		return;
	}
	int m = (l + r)/2;
	build(id * 2, l, m);
	build(id * 2 + 1, m + 1, r);
	st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
void update(int id, int l, int r, int i, char c){
	if(i < l || r < i) return;
	if(l == r){
		int prev = get(s[l]);
		st[id].c[prev]--;
		int cur = get(c);
		st[id].c[cur]++;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, i, c);
	update(id * 2 + 1, m + 1, r, i, c);
	st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v){
	node ans;
	if(r < u || v < l) return ans;
	if(u <= l && r <= v) return st[id];
	int m = (l + r)/2;
	return combine(get(id * 2, l, m, u, v), get(id * 2 + 1, m + 1, r, u, v));
}
void solve(){
	cin >> n >> m >> k;
	clear();
	cin >> s;
	s = "#" + s;
	build(1, 1, m);
	while(k--){
		int op;
		cin >> op;
		if(op == 1){
			int x, y, l, r;
			cin >> x >> y >> l >> r;
			node res = get(1, 1, m, l, r);
			x += res.c[2];
			x -= res.c[1];
			x = max(x, 1);
			x = min(x, n);

			y += res.c[4];
			y -= res.c[3];
			y = max(y, 1);
			y = min(y, n);
			cout << x << ' ' << y << nl;
		}
		else {
			int i; char c;
			cin >> i >> c;
			update(1, 1, m, i, c);
			s[i] = c;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}