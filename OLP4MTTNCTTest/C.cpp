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
const int maxn=5e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<pair<int,int>> g[maxn];
int mark[maxn],vis[maxn];
set<int> s;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	fast;
	indef();
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int x,y,w;
		cin >> x >> y >> w;
		g[x].pb({y,w});
		g[y].pb({x,w});
	}
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		mark[x]=1;
	}
}
