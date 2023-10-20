#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define rev(i,start,n) for(int (i)=(start);(i)>=(n);(i--))
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int vis[N];
int par[N];
int parNum[N];
vi digit;
void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,0,n){
		int x;cin >> x;
		digit.pb(x);
	}
	queue<int> q;
	sort(all(digit));
	rep(i,0,n){
		if(digit[i] == 0) continue;
		if(digit[i] % m == 0){
			cout << digit[i];
			return;
		}
		
		parNum[digit[i]] = digit[i];
		par[digit[i]] = digit[i];
		vis[digit[i]] = 1;
		q.push(digit[i]);
	}
	while(!q.empty()){
		int u = q.front();q.pop();
		rep(i,0,n){
			int v = (u*10 + digit[i]) % m;
			if(vis[v]) continue;
			par[v] = u;
			parNum[v] = digit[i];
			vis[v] = 1;
			q.push(v);
		}
	}
	// dbgArr(parNum,m+1);
	if(!vis[0]) cout << -1;
	else{
		vi ans;
		int tmp = 0;
		while(tmp != par[tmp]){
			ans.pb(parNum[tmp]);
			tmp = par[tmp];
		}
		ans.pb(parNum[tmp]);
		reverse(all(ans));
		for(auto x : ans) cout << x;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}