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
#define MASK(x, i) ((x) & (1 << (i)))

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
bool vis[(1 << 20) + 5];
int pos[(1 << 20) + 5];
int n; ll k;
int getMask(int mask) {
	int newMask = 0;

	for(int i = 0; i < n; i++) {
		int l = i == n - 1 ? 0 : (MASK(mask, i + 1) ? 1 : 0);
		int m = MASK(mask, i) ? 1 : 0;
		int r = i == 0 ? 0 : (MASK(mask, i - 1) ? 1 : 0);

		if(l == 0 && m == 0 && r == 1) newMask |= (1 << i);
		if(l == 0 && m == 1 && r == 0) newMask |= (1 << i);
		if(l == 1 && m == 1 && r == 0) newMask |= (1 << i);
		if(l == 1 && m == 0 && r == 1) newMask |= (1 << i);
		if(l == 0 && m == 1 && r == 1) newMask |= (1 << i);
	}
	return newMask;
}
void solve(int id){

	cin >> n >> k;
	vector<int> res, cycle;
	string s;
	cin >> s;
	reverse(all(s));
	int mask = 0, cnt = 0, left = 0;
	for(int i = 0; i < n; i++) 
		if(s[i] == '1') mask |= (1 << i);

	res.pb(mask);
	vis[mask] = 1;
	while(1) {
		mask = getMask(mask);
		if(vis[mask]) {
			for(int i = pos[mask]; i < res.size(); i++) 
				cycle.pb(res[i]);
			break;
		}
		else {
			res.pb(mask);
			vis[mask] = true;
			pos[mask] = ++cnt;
		}
	}
	int ans = 0;
	if(k < res.size()) ans = res[k];
	else {
		k -= pos[mask];
		ans = cycle[k % cycle.size()];
	}
	for(int i = n - 1; i >= 0; i--) {
		cout << (MASK(ans, i) ? 1 : 0); 
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}