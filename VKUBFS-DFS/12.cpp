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

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

vi g[maxn];
bool f[maxn];
int vis[maxn];
bool ok = true;
void dfs(int i){
	vis[i]=1;
	for(int x : g[i]){
		if(!vis[x]){
			f[x]=!f[i];
			dfs(x);
		}
		else{
			if(f[x]==f[i]){
				ok=false;
				return;
			}
		}
	}
}
int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	if(!ok) cout << "IMPOSSIBLE";
	else{
		for(int i=1;i<=n;i++){
			cout << f[i] + 1 << ' ';
		}
	}
}
