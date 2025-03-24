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
const int maxn=1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R','L','D','U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
struct node{
	int p;
	int num;
};
node par[maxn];
int vis[maxn];
int n,m,x;
vi a,ans;
queue<int> q;
void calc(){
	if(x==par[x].p){
		ans.pb(x);
		return;
	}	
	ans.pb(par[x].num);
	x=par[x].p;
	calc();
}
int main(){
	fast;
	indef();
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.pb(x);
	}
	sort(all(a));
	for(int i=0;i<n;i++){
	    if(a[i]%m==0 && a[i]){
	        cout << a[i];
	        exit(0);
	    }
		if(a[i] && !vis[a[i]]){
			q.push(a[i]);
			vis[a[i]]=1;
			par[a[i]].p=a[i];
			par[a[i]].num=a[i];
		}
	}
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i=0;i<n;i++){
			int v = ((u*10)+a[i])%m;
			if(vis[v]) continue;
			q.push(v);
			vis[v]=1;
			par[v].p=u;
			par[v].num=a[i];
		}
	}
	if(!vis[0]) cout << -1;
	else{
		calc();
		reverse(all(ans));
		for(auto x : ans) cout << x;
	}
}
