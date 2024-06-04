#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
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
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

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
ll calc(db n, db m, db x){
	db y = 1.5 * x, z = 1.0 * sqrt(3) * x;
	db rows = ceil((n - x) / y) + 1;
	ll cols_1 = ceil(m/z);
	ll cols_2 = ceil((m - (z/2))/z) + 1;
	ll ans = ceil(rows/2) * cols_1 + floor(rows/2) * cols_2;
	return ans;
}
void solve(){
	db n, m, x;
	cin >> n >> m >> x;
	cout << min(calc(n, m, x), calc(m, n, x)) << nl; 
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}