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
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

vi g[maxn];
int vis[maxn];
int x,n,m=0;
void dfs(int i){
	vis[i]=1;
	x++;
	for(int x : g[i]){
		if(!vis[x]) dfs(x);
	}
}
int main(){
	fast;
	indef();
	cin >> n;
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		m=max(m,a);
		m=max(m,b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			x=0;
			dfs(i);
			ans=max(ans,x);
		}
	}
	cout << ans;
}
