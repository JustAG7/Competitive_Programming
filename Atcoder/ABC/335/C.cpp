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

void solve(){
	int n,q;
	cin >> n >> q;
	vector<pair<int,int>> res;
	for(int i=n;i>=1;i--) res.pb({i, 0});
	int x = 1,y = 0, cnt = 0;
	for(int i=0;i<q;i++){
		int t;
		cin >> t;
		if(t == 1){
			char c;cin >> c;
			if(c == 'D') y--;
			else if(c == 'U') y++;
			else if(c == 'L') x--;
			else x++;
			cnt++;
			res.pb({x, y});
		}
		else{
			int p;cin >> p;
			auto [ansX, ansY] = res[cnt + n - p];
			cout << ansX << ' ' << ansY << nl;
		}
	}	
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}