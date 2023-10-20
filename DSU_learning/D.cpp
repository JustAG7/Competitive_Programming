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

struct DSU{
	vi par,sz;
	DSU(int n) : par(n),sz(n) {};
	void make_set(int v){
		par[v]=v;
		sz[v]=1;
	}
	int find_set(int v){
		return v == par[v] ? v : find_set(par[v]);
	}
	void union_set(int u,int v){
		u=find_set(u);
		v=find_set(v);
		if(u!=v){
			if(sz[u]<sz[v]) swap(u,v);
			par[v]=u;
			sz[u]+=sz[v];
		}
	}
};
int main(){
	fast;
	indef();
	int n,m,q;
	cin >> n >> m >> q;
	DSU g(n+5);
	for(int i=1;i<=n;i++) g.make_set(i);

}
