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

const int M=1e9+7;
const int maxn=2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<int> g[maxn];
vector<int> visit(maxn,0);
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

bool dfs(int i,int j){
	visit[i]=1;
	if(i==j) return true;
	for(auto x : g[i]){
		if(x==j) return true;
		for(auto y : g[j]){
			if(x==y) return true;
		}
	}
	return false;
}
int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	while(m--){
		int a,b;
		cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int q;
	cin >> q;
	while(q--){
		int t,a,b;
		cin >> t >> a >> b;
		if(t==1){
			g[a].pb(b);
			g[b].pb(a);
		}
		else{
			cout << ((dfs(a,b)) ? "YES" : "NO") << nl;
		}
	}
}