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
const int N = 1e3+5;
const ll inf = 1e18;
const ll INF = 0x3f;


int moveX[] = {0,  0,  1, -1};
int moveY[] = {-1, 1,  0, 0};
char moveC[] = {'L', 'R',  'D', 'U'};
void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){ 
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
bool ok;
int n, m;
char a[N][N];
void solve(int id){
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; (i + 1) * 2 <= n && (i + 1) * 2 <= m; i++) {
		vector<char> res;
		for(int j = i; j < (m - i); j++) res.pb(a[i][j]);
		for(int j = i + 1; j < (n - i - 1); j++) res.pb(a[j][m - i - 1]);
		for(int j = (m - i - 1); j >= i; j--) res.pb(a[n - i - 1][j]);
		for(int j = (n - i - 2); j >= i + 1; j--) res.pb(a[j][i]);
		int m = res.size();
		for(int j = 0; j < m; j++) {
			string t = "";
			for(int k = j; k < j + 4; k++) {
				t += res[k % m];
			}
			if(t == "1543") ans++;
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();

	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}