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
	vi par,sz,mx,mn;

	DSU(int n) : par(n),mx(n),sz(n),mn(n) {};
	void make_set(int v){
		par[v]=v;
		mx[v]=v;
		mn[v]=v;
		sz[v]=1;
	}
	int find_set(int v){
		return v==par[v] ? v : par[v]=find_set(par[v]);
	}
	int find_max(int v){
		return mx[v];
	}
	int find_min(int v){
		return mn[v];
	}
	int find_size(int v){
		return sz[v];
	}
	void union_set(int a,int b){
		a = find_set(a);
		b = find_set(b);
		if(a!=b){
			if(sz[a]<sz[b]) swap(a,b);
			par[b]=a;
			sz[a]+=sz[b];
			mn[a]=min(mn[a],mn[b]);
			mx[a]=max(mx[a],mx[b]);
		}
	}
};
int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	DSU g(n+5);
	for(int i=1;i<=n;i++) g.make_set(i);
	while(m--){
		string s;int a,b;
		cin >> s;
		if(s=="union"){
			cin >> a >> b;
			g.union_set(a,b);
		}
		else{
			cin >> a;
			int ans = g.find_set(a);
			cout << g.find_min(ans) << ' ' << g.find_max(ans) << ' ' << g.find_size(ans) << "\n";
		}
	}
}
