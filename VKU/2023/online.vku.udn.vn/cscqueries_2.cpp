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
const int C = 50;
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
ll a[N];
int n;
struct BIT{
	int size;
	vector<vector<ll>> bit;

	void init(int newSize){
		size = newSize;
		bit.resize(size + 2, vector<ll> (n/size + 2, 0));
		for(int i=1;i<=n;i++){
			update(i % size, i / size + (i % size != 0), a[i]);
		}
	}

	void update(int k,int u,int val){
		for(; u <= n/size + (n % size != 0); u += u & (-u)){
			bit[k % size][u] += val;
		}
	}

	ll query(int u,int k){
		ll ans = 0;
		for(;u > 0; u -= u & (-u)){
			ans += bit[k % size][u];
		}
		return ans;
	}

	ll getRange(int u,int k){
		return query(n/size + (n % size != 0) ,k) - query(u - 1,k);
	}
	void print(){ //print the array after operations
		for(int i=1;i<size;i++){
			for(int j=1;j <= n / size;j++)
				cout << bit[i][j] << ' ';
			cout << nl;
		}
		for(int j=1;j <= n / size;j++)
			cout << bit[0][j] << ' ';
		cout << nl;
	}
};

void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	BIT bit[min(n, C) + 2];
	for(int i=1;i<=min(n, C);i++){
		bit[i].init(i);
		// bit[i].print();
	}
	int q;
	cin >> q;
	for(int i=0;i<q;i++){
		int t,u,v;
		cin >> t >> u >> v;

		if(t == 1){
			for(int i=1;i<=min(n, C);i++){
				bit[i].update(u, u/i + (u % i != 0), -a[u] + v);
			}
			a[u] = v;
		}
		else{
			if(v > C){
				ll ans = 0;
				for(;u <= n;u += v) ans += a[u];
				cout << ans << nl;
			}
			else{
				cout << bit[v].getRange(u/v + (u % v != 0), u) << nl;
			}
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