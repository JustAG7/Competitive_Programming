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
const int N = 1e6+5;
const ll inf = 1e18;
const ll INF = 0x3f;
const int base = 101;


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

ll bit[2][N];
ll POW[N];
int n,q;
void update(int u,ll val,int k){
	val %= M;
	if(val < M) val += M; // negative fix
	for(;u < N;u += u & (-u)){
		(bit[k][u] += val) %= M;
	}
}

ll query(int u,int k){
	ll ans = 0;
	for(;u > 0;u -= u & (-u)){
		(ans += bit[k][u]) %= M;
	}
	return ans;
}
void solve(){
	cin >> n >> q;
	string s;
	cin >> s;
	POW[0] = 1;
	for(int i=1;i < N;i++)
		POW[i] = (POW[i - 1] * base) % M;
	
	for(int i=0;i<n;i++) {
		ll lt = s[i] - 'a' + 1;
		update(i + 1,lt * POW[i],0);
		update(i + 1,lt * POW[n - i - 1],1);
	}

	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int x; char c;
			cin >> x >> c;x--;
			ll lt = s[x] - 'a' + 1;
			update(x + 1, -lt * POW[x],0);
			update(x + 1, -lt*POW[n - x - 1],1);
			lt = c - 'a' + 1;
			update(x + 1, lt * POW[x],0);
			update(x + 1, lt*POW[n - x - 1],1);
			s[x] = c;
		}
		else{
			int l,r;
			cin >> l >> r;
			int m1 = (l + r)/2;
			int m2 = (l + r - 1)/2;

			ll left = (query(m1,0) - query(l - 1,0) + M) % M;
			ll right = (query(r,1) - query(m2,1) + M) % M;

			cout << (left*POW[n - r]%M == right*POW[l - 1]%M ? "Yes\n" : "No\n");
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