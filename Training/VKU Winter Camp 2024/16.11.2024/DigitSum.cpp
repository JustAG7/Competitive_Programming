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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
string s;
ll dp[16][180][3];
ll calc(int pos, int num, bool tight) {
	if(pos >= s.size()) return num;
	ll &ans = dp[pos][num][tight];
	if(ans != -1) return ans;
	ans = 0;
	int lim = tight ? 9 : s[pos] - '0';
	for(int i = 0; i <= lim; i++) {
		ans += calc(pos + 1, num + i, tight || (i < s[pos] - '0'));
	}
	return ans;
}
void solve(int id){
	ll a, b;
	cin >> a >> b;
	if(a == 0) {
		memset(dp, -1, sizeof dp);
		s = to_string(b);
		cout << calc(0, 0, 0) << nl;
		return;
	}
	a--;
	s = to_string(a);
	memset(dp, -1, sizeof dp);
	ll l = calc(0, 0, 0);
	s = to_string(b);
	memset(dp, -1, sizeof dp);
	ll r = calc(0, 0, 0);
	cout << r - l << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}