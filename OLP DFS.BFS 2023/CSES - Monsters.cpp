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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define rev(i,start,n) for(int (i)=(start);(i)>=(n);(i--))
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int f1[N][N],f2[N][N];
vi g[N];
queue<ii> q;
ii parPos[N][N], start;
char par[N][N], mat[N][N];
int vis[N][N];
int n,m;
vector<char> ans;
bool check(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs1(){
	while(!q.empty()){
		auto [u,v] = q.front();q.pop();
		rep(i,0,4){
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx,dy) && mat[dx][dy] != '#' && !vis[dx][dy]){
				f1[dx][dy] = f1[u][v] + 1;
				vis[dx][dy] = 1;
				q.push({dx,dy});
			}
		}
	}
}
void clear(){
	while(!q.empty()) q.pop();
	q.push(start);
	memset(vis,0,sizeof(vis));
	par[start.X][start.Y] = '*';
	vis[start.X][start.Y] = 1;
}
void bfs2(){
	while(!q.empty()){
		auto [u,v] = q.front();q.pop();
		rep(i,0,4){
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx,dy) && mat[dx][dy] != '#' && mat[dx][dy] != 'M' && !vis[dx][dy] && f2[u][v] + 1 < f1[dx][dy]){
				f2[dx][dy] = f2[u][v] + 1;
				parPos[dx][dy] = make_pair(u,v);
				par[dx][dy] = moveC[i];
				vis[dx][dy] = 1;
				q.push({dx,dy});
			}
		}
	}
}
void getAns(int x,int y){
	int tmpx = x, tmpy = y;
	while(par[tmpx][tmpy] != '*'){
		ans.pb(par[tmpx][tmpy]);
		auto [nx,ny] = parPos[tmpx][tmpy];
		tmpx = nx, tmpy = ny;
	}
	cout << "YES\n";
	cout << ans.size() << nl;
	reverse(all(ans));
	for(auto x : ans) cout << x;
}
void solve(){
	cin >> n >> m;
	rep(i,0,n){
		rep(j,0,m){
			cin >> mat[i][j];
			if(mat[i][j] == 'M'){
				q.push({i,j});
				vis[i][j] = 1;
				f1[i][j] = 0;
			}
			if(mat[i][j] == 'A'){
				start = make_pair(i,j);
				vis[i][j] = 1;
				f2[i][j] = 0;
			}
			if(mat[i][j] == '.'){
				f1[i][j] = 2e9;
			}
		}
	}
	bfs1(); //bfs for monster to get min distance to all '.'
	clear();
	bfs2(); // bfs for player to check which '.' the player can go
			// but the monsters wont get there first
	// check the border, if it's okay then return
	rep(i,0,n){
		if(vis[i][0]){
			return getAns(i,0);
		}
		if(vis[i][m - 1] ){
			return getAns(i,m - 1);
		}
	}
	rep(i,0,m){
		if(vis[0][i]){
			return getAns(0,i);
		}
		if(vis[n - 1][i]){
			return getAns(n - 1,i);
		}
	}

	cout << "NO";
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}