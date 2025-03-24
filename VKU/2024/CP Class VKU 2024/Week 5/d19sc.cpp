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
const int N = 505;
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
int a[N][N];
int cnt[6][N][N];
int f[6][N][N];
bool check(int x,int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}
void pfs(int type) {
	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
	pq.push({cnt[type][1][1], 1, 1});
	f[type][1][1] = cnt[type][1][1];
	while(pq.size()) {
		auto [w, x, y] = pq.top();pq.pop();
		if(f[type][x][y] != w) continue;
		for(int i=0;i<4;i++){
			int dx = x + moveX[i];
			int dy = y + moveY[i];
			if(check(dx, dy) && f[type][dx][dy] > f[type][x][y] + cnt[type][dx][dy]) {
				f[type][dx][dy] = f[type][x][y] + cnt[type][dx][dy];
				pq.push({f[type][dx][dy], dx, dy});
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			f[2][i][j] = M;
			f[5][i][j] = M;
			cin >> a[i][j];
			while(a[i][j] % 2 == 0) {
				cnt[2][i][j]++;
				a[i][j] /= 2;
			}
			while(a[i][j] % 5 == 0) {
				cnt[5][i][j]++;
				a[i][j] /= 5;
			}
		}
	}
	pfs(2); pfs(5);
	cout << min(f[2][n][m], f[5][n][m]);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}