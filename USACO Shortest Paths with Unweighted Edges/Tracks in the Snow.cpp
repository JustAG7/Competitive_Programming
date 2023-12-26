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
const int N = 4e3+5;
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

char snow[N][N];
int dist[N][N];
int h,w;
int ans = 0;
bool check(int x,int y){
	return 0 <= x && x < h && 0 <= y && y < w && snow[x][y] != '.';
}
void bfs01(){
	deque<ii> dq;
	dq.pb({0, 0});
	dist[0][0] = 1;
	while(!dq.empty()){
		auto [x, y] = dq.front();dq.pop_front();
		ans = max(ans, dist[x][y]);
		for(int i=0;i<4;i++){
			int dx = x + moveX[i];
			int dy = y + moveY[i];
			if(check(dx,dy) && !dist[dx][dy]){
				if(snow[dx][dy] == snow[x][y]){
					dist[dx][dy] = dist[x][y];
					dq.push_front({dx, dy});
				}
				else{
					dist[dx][dy] = dist[x][y] + 1;
					dq.pb({dx, dy});
				}
			}
		}
	}
}
void solve(){
	cin >> h >> w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> snow[i][j];
		}
	}

	bfs01();
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}