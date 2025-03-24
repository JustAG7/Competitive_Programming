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
#define iii pair<int, pair<int, int>>


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

int n, numP, m;
vector<iii> p;

ii cur[4];
int dir[4] = {0};

int flag = 0;

ii moveA(int x, int y, int d, int val) {
	if(d == 0) {
		x = (x + n*2 - val) % n;
	}
	else if (d == 1) {
		y = (y + val) % n;
	}
	else if (d == 2) {
		x = (x + val) % n;
	}
	else if (d == 3) {
		y = (y + n * 2 - val) % n;
	}
	return {x, y};
}

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(int id){
	cin >> n >> numP >> m;
	for(int i =0; i < 4; ++i) {
		dir[i] = i;
		cur[i] = {0, 0};
	}
	for(int i = 0; i < numP; ++i) {
		int u, v, d; cin >> u >> v >> d;
		p.push_back({d, {u, v}});
	}
	for(int mi = 0; mi < m; ++mi) {
		char query; int x;
		cin >> query >> x;
		if(query == 'A') {
			for(int pi = 0; pi < 4; ++pi) {
				cur[pi] = moveA(cur[pi].X, cur[pi].Y, dir[pi], x);
			}
		}
		else if(query == 'R') {
			for(int pi = 0; pi < 4; ++pi) {
				dir[pi] += x;
				dir[pi] %= 4;
			}
		}
		else {
			int kx = x / n;
			int ky = x % n;
			for(int pi = 0; pi < 4; ++pi) {
				cur[pi] = {kx, ky};
			}
			flag = 1;
		}
	}
	for(iii pi : p) {
		int px = pi.Y.X;
		int py = pi.Y.Y;
		int pd = pi.X - 1;
		if(!flag)
			cout << (px + cur[pd].X) % n << " " << (py + cur[pd].Y) % n << '\n';
		else {
			cout << cur[pd].X << " " << cur[pd].Y << '\n';
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	for(int t = 1; t <= tt; t++) solve(t);
}