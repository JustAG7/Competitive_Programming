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

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

int a[15][15][15];

void solve(int id){
	int n;
	cin >> n;
	vector<array<int, 4>> a;
	int m = n * n - n;

	for(int z = 1; z <= n; z++) {
		for(int x = 1; x <= n; x++) {
			for(int y = 1; y <= n; y++) {
				int val; cin >> val;
				a.pb({val, x, y, z});
			}
		}
	}	
	set<int> sX, sY, sZ;
	sort(all(a));
	int ans = 0, cnt = 0;
	for(int i = 0; i < n * n * n; i++) {
		if(cnt == n) break;
		auto [val, x, y, z] = a[i];
		bool ok = true;
		ok &= (sX.find(x) == sX.end());
		ok &= (sY.find(y) == sY.end());
		ok &= (sZ.find(z) == sZ.end());
		if(!ok) continue;
		ans += val;
		cout << x << ' ' << y << ' ' << z << ' ' << val << nl;
		cnt++;
		sX.insert(x);
		sY.insert(y);
		sZ.insert(z);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}