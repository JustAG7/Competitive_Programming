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
const int maxn=1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int g[maxn][maxn];
char par[maxn][maxn];
pair<int,int> px[maxn][maxn];
int vis[maxn][maxn];
int a,b,x,y;
int n,m;
vector<char> ans;
void calc(){
	if(x==px[x][y].X && y==px[x][y].Y) return;
	ans.pb(par[x][y]);
	int ox = x;
	x=px[ox][y].X;y=px[ox][y].Y;
	calc();
}
void bfs(){
	vis[a][b]=1;
	par[a][b]='#';
	px[a][b]=make_pair(a,b);
	queue<pair<int,int>> q;
	q.push({a,b});
	while(!q.empty()){
		auto p = q.front(); q.pop();
		int r = p.X, c = p.Y;
		for(int i=0;i<4;i++){
			int dx=r+moveX[i],dy=c+moveY[i];
			if(0<=dx && dx<n && 0<=dy && dy<m && g[dx][dy]==1 && !vis[dx][dy]){
				vis[dx][dy]=1;
				par[dx][dy]=moveC[i];
				px[dx][dy].X = r; px[dx][dy].Y = c;
				q.push({dx,dy});
				if(dx==x && dy==y) return;
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
			if(s!='#') g[i][j]=1;
			if(s=='A') {a=i;b=j;}
			if(s=='B') {x=i;y=j;}
		}
	}
	bfs();
	if(!vis[x][y]) cout << "NO";
	else{
		calc();
		cout << "YES\n";
		cout << ans.size() << nl;
		reverse(all(ans));
		for(char x : ans) cout << x;
	}
}
