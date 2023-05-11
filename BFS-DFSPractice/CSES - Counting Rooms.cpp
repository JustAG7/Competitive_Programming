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
#define nl '\n'

const ll M=1e9+7;
const int maxn=1e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

vector<vector<int>> a(maxn,vector<int> (maxn,0));
int n,m;
void dfs(int x,int y){
	a[x][y]=1;
	for(int i=0;i<4;i++){
		int dx=x+moveX[i],dy=y+moveY[i];
		if(0<=dx && dx<n && 0<=dy && dy<m && !a[dx][dy]){
			dfs(dx,dy);
		}
	}
}
int main(){
	fast;
	indef();
	int ans=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		for(int j=0;j<s.size();j++){
			if(s[j]=='#') a[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!a[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout << ans;
}