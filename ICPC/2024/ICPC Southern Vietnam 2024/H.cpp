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
#define getBIt(x, n) (x >> n) & 1


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

int n, m;
string s[1010];

int trau(int row, int col, int base, int pre) {
	if(row > n) {
		return 0;
	}
	if(col == m) {
		return trau(row+1, 0, base, 0);
	}
	int res = 0;
	if(s[row][col] == '#' and (((base >> col) & 1) or pre) ) {
		if((base >> col) & 1) {
			int case1 = trau(row, col + 1, base ^ (1<<col), 1) + 1;
			int case2 = trau(row, col + 1, base, 0);
			res += min(case1, case2);
		}
		else {
			int case1 = trau(row, col + 1, base | (1<<col), 0) + 1;
			int case2 = trau(row, col + 1, base, 1);
			res += min(case1, case2);
		}
	}
	else if(s[row][col] == '.') {
		res += trau(row, col+1, base ^ (1 << col), 0);
	}
	else {
		int case1 = trau(row, col+1, base, 1) + 1;
		int case2 = trau(row, col+1, base | (1 << col), 0) + 1;
		res += min(case1, case2);
	}
	return res;
}

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(int id){
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	cout << trau(1, 0, 0, 0);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}