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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int vis[N][N];
int n,m;
char mat[N][N];
bool check(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
void bfs(int x,int y){
	vis[x][y] = 1;
	queue<pair<int,int>> q;
	q.push({x,y});
	while(!q.empty()){
		auto [u,v] = q.front();q.pop();
		rep(i,0,4){
			int dx = u + moveX[i];
			int dy = v + moveY[i];
			if(check(dx,dy) && mat[dx][dy] != '#' && !vis[dx][dy]){
				vis[dx][dy] = 1;
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
		}
	}
	int ans = 0;
	rep(i,0,n){
		rep(j,0,m){
			if(mat[i][j]=='.' && !vis[i][j]){
				bfs(i,j);
				ans++;
			}
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}