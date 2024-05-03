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

int t[4 * N], a[N];
string s;
int n, q;
void update(int id,int l,int r,int u,int val){
	if(r < u || u < l) return;
	if(l == r){
		t[id] = val;
		return;
	}
	int m = (l + r)/2;
	update(id * 2, l, m, u, val);
	update(id * 2 + 1, m + 1, r, u, val);
	t[id] = t[id * 2] + t[id * 2 + 1];
}

int get(int id,int l,int r,int u,int v){
	if(r < u || v < l) return 0;
	if(u <= l && r <= v){
		return t[id];
	}

	int m = (l + r)/2;
	return get(id * 2,l,m,u,v) + get(id * 2 + 1,m + 1,r,u,v);
}
void solve(){
	cin >> n >> q;
	cin >> s;
	for(int i=0;i<n-1;i++){
		if(s[i] != s[i + 1]){
			// cout << i + 1 << ' ';
			update(1, 1, n, i + 1, 1);
		}
	}

	while(q--){
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1){
			update(1, 1, n, l - 1, 1 - get(1, 1, n,l - 1,l - 1));
			update(1, 1, n, r, 1 - get(1, 1, n,r,r));
		}
		else{
			int sum = get(1, 1, n, l, r - 1);
			cout << (sum == (r - l) ? "Yes" : "No") << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}