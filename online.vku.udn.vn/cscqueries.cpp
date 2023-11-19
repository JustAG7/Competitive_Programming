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
const int C = 500;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
struct BIT{
	int n;
	vector<ll> bit;
	
}
ll a[N];
int n;
void update(int pos,ll val){
	for(int i=1;i<=C;i++){
		for(int x = pos; x <= n; x += x & (-x)){
			bit[x][i] -= a[pos];
			bit[x][i] += val;
		}
	}
}
ll query(int x,int k){
	ll ans = 0;
	for(; x > 0; x -= x & (-x)) ans += bit[x][k];
	return ans;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		update(i, a[i]);
	}
	int q;
	cin >> q;
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int pos; ll val; cin >> pos >> val;
			update(pos, val);
			a[pos] = val;
		}
		else{
			int pos, k; cin >> pos >> k;
			if(k >= C){
				ll ans = 0;
				for(; pos <= n; pos += k) ans += a[pos];
				cout << ans << nl;
			}
			else cout << query(pos, k) << nl;

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