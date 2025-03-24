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
const int N = 3e5+5;
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

pair<ll,ll> a[N];
ll f[3];
ll calc(pair<ll,ll> a, pair<ll,ll> b) {
	return 1LL * (a.X - b.X) * (a.X - b.X)
		+  1LL * (a.Y - b.Y) * (a.Y - b.Y);
}
void solve(int id){
	ll n, f0, d;
	cin >> n >> f0 >> d;
	d *= d;
	queue<int> q, p;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].X >> a[i].Y;
		if(i == f0) q.push(i);
		else p.push(i);
	}
	for(int i = 1; i <= 2; i++) {
		int n = q.size();
		for(int k = 0; k < n; k++) {
			int x = q.front();q.pop();
			int m = p.size();
			for(int j = 0; j < m; j++) {
				int y = p.front();p.pop();
				ll dist = calc(a[x], a[y]);
				if(dist < d) {
					f[i]++;
					q.push(y);
				}
				else p.push(y);
			}
		}
	}
	cout << f[1] << ' ' << f[2];	
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}