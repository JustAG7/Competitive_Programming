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
const int N = 2e5+5;
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

ll bit[10][N], a[N];
int n,q;
void update(int u,ll val,int k){
	for(;u <= n;u += u & (-u)){
		bit[k][u] += val;
	}
}
ll query(int u,int k){
	ll ans = 0;
	for(;u > 0;u -= u & (-u)){
		ans += bit[k][u];
	}
	return ans;
}
bool check(int i,int k){
	if(i % k == 0) return true;
	while(i > 0){
		if((i % 10) == k) return true;
		i /= 10;
	}
	return false;
}
void solve(){
	cin >> n >> q;
	for(int i=1;i<=n;i++){
		int x;cin >> x;
		update(i,x,0);
		for(int j=1;j<=9;j++){
			if(check(i, j)) update(i,x,j);
		}
		a[i] = x;
	}

	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int i,c;
			cin >> i >> c;
			update(i, -a[i] + c, 0);
			for(int j=1;j<=9;j++){
				if(check(i, j)) update(i, -a[i] + c, j);
			}
			a[i] = c;
		}
		else{
			int l,r,k;
			cin >> l >> r >> k;
			ll ans = query(r,0) - query(l - 1,0) + query(r,k) - query(l - 1, k);
			cout << ans << nl;
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