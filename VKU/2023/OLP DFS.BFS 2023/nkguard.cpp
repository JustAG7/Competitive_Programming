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

int moveX[8] = {-1,-1,-1,0,0,1,1,1};
int moveY[8] = {-1, 0,1,-1,1,-1,0,1};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int mat[N][N];
int vis[N][N];
int n,m;
bool ok;
bool check(int x,int y){
	return 0 <= x && x < n && 0 <= y && y < m;
}
void dfs(int u,int v){
	vis[u][v] = 1;
	rep(i,0,8){
		int dx = u + moveX[i];
		int dy = v + moveY[i];
		if(check(dx,dy)){
			if(mat[dx][dy] == mat[u][v] && !vis[dx][dy]) dfs(dx,dy);
			else if(mat[dx][dy] > mat[u][v]) ok = false;
		}
	}
}
void solve(){
	cin >> n >> m;
	rep(i,0,n)
		rep(j,0,m)
			cin >> mat[i][j];
	int ans = 0;
	rep(i,0,n){
		rep(j,0,m){
			if(!vis[i][j]){
				ok = true;
				dfs(i,j);
				ans += ok;
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