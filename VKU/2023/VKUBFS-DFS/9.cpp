#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define vi vector<int> 
#define vvi vector<vector<int>> 

const int M=1e9+7;
const int maxn=105;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int g[maxn][maxn];
int vis[maxn][maxn];
int a,b,x,y;
int n,m;
void bfs(){
	vis[a][b]=1;
	queue<pair<int,int>> q;
	q.push({a,b});
	while(!q.empty()){
		auto p = q.front();q.pop();
		int r = p.X, c = p.Y;
		for(int i=0;i<4;i++){
			int dx=r+moveX[i],dy=c+moveY[i];
			if(0<=dx && dx<n && 0<=dy && dy<m && g[dx][dy]!=-1 && !vis[dx][dy]){
				g[dx][dy]=g[r][c]+1;
				vis[dx][dy]=1;
				q.push({dx,dy});
			}
		}
	}
}
int main(){
	fast;
	indef();
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char s; cin >> s;
			if(s=='*') g[i][j]=-1;
			else if(s=='B') {a=i;b=j;}
			else if(s=='C') {x=i;y=j;}
		}
	}
	/*
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << g[i][j] << ' ';
		}
		cout << nl;
	}
	*/
	bfs();
	cout << g[x][y] << nl;
}
