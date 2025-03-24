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
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

struct BIT {
	int n;
	long long nodes[110][110][110] = {0};
	void init(int _n) {
		n = _n;
		memset(nodes, 0, sizeof nodes);
	}
	void upd(int x, int y, int z, int val) {
		int x1 = x, y1 = y, z1 = z;
		for(x = x1; x <= n; x += x&-x)
			for(y = y1; y <= n; y += y&-y)
				for(z = z1; z <= n; z += z&-z) {
					nodes[x][y][z] += val;
				}

	}
	long long get(int x, int y, int z) {
		ll res = 0;
		int x1 = x, y1 = y, z1 = z;
		for(x = x1; x > 0; x-= x&-x)
			for(y = y1; y > 0; y-= y&-y)
				for(z = z1; z > 0; z-= z&-z)
					res += nodes[x][y][z];
		return res;
	}
	ll get(int x1, int y1, int z1, int x2, int y2, int z2) {
		return get(x2, y2, z2) 
		- get(x1-1, y2, z2) - get(x2, y1-1, z2) - get(x2, y2, z1-1)
		+ get(x1-1, y1-1, z2) + get(x1-1, y2, z1-1) + get(x2, y1-1, z1-1) 
		- get(x1 - 1, y1 - 1, z1 - 1);
	}

} T;


void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int a[110][110][110];
void solve(int id){
	// cerr << id << '\n';
	int n, q;
	cin >> n >> q;
	memset(a, 0, sizeof(a));
	T.init(n);
	for(int qi = 0; qi < q; ++qi) {
		string query; cin >> query;
		// cout << query << nl;
		if(query == "UPDATE") {
			int x, y, z, v; cin >> x >> y >> z >> v;
			T.upd(x, y, z, v - a[x][y][z]);
			a[x][y][z] = v;
		}
		else {
			int x1, y1, z1, x2, y2, z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << T.get(x1, y1, z1, x2, y2, z2) << '\n';
		}
	}

}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) {
		solve(t);
	}
}