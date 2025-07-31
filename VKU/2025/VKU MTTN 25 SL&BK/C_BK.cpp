#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 2e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

int a[N];
vector<int> g[N];
int getPos(int x, int y) {
	int ans = -1, l = 0, r = g[x].size() - 1;
	while(l <= r) {
		int m = (l + r) / 2;
		if(g[x][m] >= y) {
			ans = g[x][m];
			r = m - 1;
		}
		else l = m + 1;
	}
	return ans;
}
void solve(int id){
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		cin >> a[i];
		g[a[i]].pb(i + 1);
	}
	int ans = 1, cur = 0;
	for(int i = 1; i <= m; i++) {
		int pos = getPos(i, cur);
		if(pos > cur) cur = pos;
		else {
			ans++;
			cur = g[i][0];
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	for(int t = 1; t <= tt; t++) solve(t);
}