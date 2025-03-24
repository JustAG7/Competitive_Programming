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

int f[maxn][maxn];
int vis[maxn][maxn];
int cnt=0;
int n,m,k;
int a,b,x,y;
queue<pair<int,int>> q;
void spread(){
	int size = q.size();
	if(size()==0) return;
	for(int i=0;i<size();i++){
		auto p = q.front();q.pop();
		int r = p.X , c = p.Y;
		vis[r][c]=1;
		for(int j=0;j<4;j++){
			int dx = r+moveX[i], dy=c+moveY[i];
			if(0<=dx && dx<n && 0<=dy && dy<m && !vis[dx][dy]){
				q.push(dx,dy);
				vis[dx][dy]=1;
			}
		}
	}
}
int main(){
	fast;
	indef();
	cin >> n >> m >> k;
	memset(f,k,sizeof(f));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char s; cin >> s;
			if(s=='H') {a=i;b=j;}
			else if(s=='S') {q.push({i,j});}
			else if(s=='G') {x=i;y=j;}
		}
	}
	q.push({oa,ob});
	for(int i=1;i<=n+m;i++){

	}
}
