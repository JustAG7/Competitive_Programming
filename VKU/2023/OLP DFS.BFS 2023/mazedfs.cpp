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
ii parPos[N][N];
int vis[N][N];
char par[N][N];
int n,m;
char mat[N][N];
ii finish;
queue<ii> q;
bool check(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs(){

	while(!q.empty()){
		auto [u,v] = q.front();q.pop();
		rep(i,0,4){
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx,dy) && mat[dx][dy] != '#' && !vis[dx][dy]){
				parPos[dx][dy] = make_pair(u,v);
				vis[dx][dy] = 1;
				par[dx][dy] = moveC[i];
				q.push({dx,dy});
			}
		}
	}
}
void solve(){
	cin >> n >> m;
	rep(i,0,n){
		rep(j,0,m){
			cin >> mat[i][j];
			if(mat[i][j] == 'A'){
				q.push({i,j});
				parPos[i][j] = make_pair(i,j);
				vis[i][j] = 1;
				par[i][j] = '*';
			}
			if(mat[i][j] == 'B'){
				finish = make_pair(i,j);
			}
		}
	}
	bfs();
	auto [x,y] = finish;
	if(!vis[x][y]) cout << "NO";
	else{
		cout << "YES\n";
		vector<char> ans;
		int tmpx = x, tmpy = y;
		while(par[tmpx][tmpy] != '*'){
			ans.pb(par[tmpx][tmpy]);
			auto [nx,ny] = parPos[tmpx][tmpy];
			tmpx = nx, tmpy = ny;
		}
		cout << ans.size() << nl;
		reverse(all(ans));
		for(auto x : ans) cout << x;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}