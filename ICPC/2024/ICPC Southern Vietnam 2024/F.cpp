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
const int N = 5e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen("INPUT.ans","w",stdout);	
	}
}
int a[N];
map<int,int> mp, roll;
int n, m, d, k;
int q;
int lazySet[3][4 * N];
int st[3][4 * N];
int thuan = 0, an = 0;
vector<int> res;

void pushDown(int id,int l,int r, int type){
	int m = (l + r)/2;
	if(lazySet[type][id] != -1){

		lazySet[type][id * 2 + 1] = lazySet[type][id];
		lazySet[type][id * 2] = lazySet[type][id];

		st[type][id * 2] = lazySet[type][id];
		st[type][id * 2 + 1] = lazySet[type][id];

		lazySet[type][id] = -1;
	}

}

void pullUp(int id,int type){
	st[type][id] = st[type][id * 2] + st[type][id * 2 + 1];
}
void SET(int id,int l,int r,int u,int v,int x,int type){
	if(v < l || r < u) return;
	if(u <= l && r <= v){
		st[type][id] = x;
		lazySet[type][id] = x;
		return;
	}
	int m = (l + r)/2;
	pushDown(id, l, r, type);
	SET(id * 2, l, m, u, v, x, type);
	SET(id * 2 + 1, m + 1, r, u, v, x, type);
	pullUp(id, type);
}	
void SETRange(int l,int r,int x,int type){
	SET(1, 1, n, l, r, x, type);
}
int get(int id,int l,int r,int u,int v,int type){
	if(v < l || r < u) return 0;
	if(u <= l && r <= v) return st[type][id];
	int m = (l + r)/2;
	pushDown(id, l, r, type);
	return get(id * 2, l, m, u, v, type) + get(id * 2 + 1, m + 1, r, u, v, type);
}
int getRange(int l,int r,int type){
	return get(1, 1, n, l, r, type);
}
void calcThuan() {
	int l = 0, r = 0;
	bool ok = false;
	for(int i=1;i<=n;i++) {
		if(getRange(i, i, 1) == 1) {
			if(!ok) {
				l = roll[i];
				r = roll[i];
				ok = true;
			}			
			else r = roll[i];
		}
		else if(ok) {
			thuan = max(thuan, r - l + 1);
			ok = false;
		}
	}
	if(ok) thuan = max(thuan, r - l + 1);
}
void calcAn() {
	int tmp = 0, l = 0, r = 0;
	bool ok = false;
	for(int i=1;i<=n;i++) {
		if(getRange(i, i, 0) == 1) {
			if(!ok) {
				l = roll[i];
				r = roll[i];
				ok = true;
			}			
			else r = roll[i];
		}
		else if(ok) {
			an = max(an, r - l + 1);
			ok = false;
		}
	}
	if(ok) an = max(an, r - l + 1);
}
void solve(int id){
	int C;
	cin >> C;
	cin >> k >> m >> d;
	for(int i=1;i<=m * 2;i++) {
		cin >> a[i];
		res.pb(a[i]);
		if(a[i] + d - 1 <= k - 1) res.pb(a[i] + d - 1);
		if(a[i] - 1 >= 0) res.pb(a[i] - 1);
		if(a[i] + d <= k - 1) res.pb(a[i] + d);
	}
	sort(all(res));
	res.erase(unique(all(res)), res.end());
	n = res.size();
	for(int i=0;i<res.size();i++) {
		mp[res[i]] = i + 1;
		roll[i + 1] = res[i];
	}
	for(int i=1;i<=m * 2;i++) {
		int type = i & 1;
		if(a[i] + d - 1 > k - 1) {
			if(i & 1) thuan++;
			else an++;
			continue;
		}
		int l = mp[max(0, a[i] - 1)], r = mp[min(k - 1, a[i] + d)];
		// cout << l << ' ' << r << nl;
		int exist = getRange(l, r, 1 - type);
		l = mp[a[i]], r = mp[a[i] + d - 1];
		if(exist > 0) {
			if(i & 1) thuan++;
			else an++;
		}
		else SETRange(l, r, 1, type);
		
	}
	if(C == 1) cout << thuan << ' ' << an << nl;
	else {
		thuan = 0, an = 0;
		calcThuan(); calcAn();	
		cout << thuan << ' ' << an << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}