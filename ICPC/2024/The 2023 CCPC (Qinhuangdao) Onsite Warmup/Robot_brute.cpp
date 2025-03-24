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
	int n, m, k;
	string s;
	cin >> n >> m >> k;
	cin >> s;
	s = "#" + s;
	while(k--){
		int op;
		cin >> op;
		if(op == 2) {
			int i; char c;
			cin >> i >> c;
			s[i] = c;
		}
		else {
			int x, y, l, r;
			cin >> x >> y >> l >> r;
			for(int i=l;i<=r;i++){
				if(s[i] == 'U') x--;
				if(s[i] == 'D') x++;
				if(s[i] == 'L') y--;
				if(s[i] == 'R') y++;
				
				if(x < 1) x = 1;
				if(x > n) x = n;
				if(y < 1) y = 1;
				if(y > n) y = n;
			}
			cout << x << ' ' << y << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}