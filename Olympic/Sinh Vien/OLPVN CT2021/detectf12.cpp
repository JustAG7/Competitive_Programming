#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define int long long
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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 1e4+5;
const ll inf = 1e18;
const ll INF = 0x3f;
const db eps = 1e-4;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ii f[N];
int check[N];
set<ii> f1;
db dist(ii &a, ii &b){
	return sqrt((a.X - b.X) * (a.X - b.X) + (a.Y - b.Y) * (a.Y - b.Y));
}
void solve(){
	int ans1 = 0, ans2 = 0;
	int n, index;
	db d;
	cin >> n >> index >> d;
	index--;
	ii f0;
	for(int i=0;i<n;i++){
		cin >> f[i].X >> f[i].Y;
		if(i == index){
			f0 = f[i];
			check[i] = 1;
			continue;
		}
	}
	for(int i=0;i<n;i++){
		if(check[i]) continue;
		if(dist(f[i], f0) < d){
			f1.insert(f[i]);
			check[i] = 1;
			ans1++;
		}
	}
	for(int i=0;i<n;i++){
		if(check[i]) continue;
		for(auto p : f1){
			if(dist(f[i], p) < d){
				ans2++;
				break;
			}
		}
	}
	cout << ans1 << ' ' << ans2;
}
signed main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}