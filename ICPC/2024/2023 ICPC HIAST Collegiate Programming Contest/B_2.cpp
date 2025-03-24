// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
const int LG = 22;
const int N = 2e6+5;
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
int divisor[N], a[N];
int cnt[N];
int rmq[LG][N];
int n, q;
void sieve(){
	for(int i=2;i<=N-5;i++){
		if(divisor[i]) continue;
		for(int j=i;j<=N-5;j+=i){
			divisor[j] = i;
		}
	}
}
void initRMQ() {
	for(int t = 1; t < LG; t++) {
		for(int i = 1, j = (1 << t), k = j / 2 + 1; j <= n; i++, j++, k++){
			rmq[t][i] = max(rmq[t - 1][i], rmq[t - 1][k]);
		}
	}
}
void solve(){
	cin >> n >> q;
	priority_queue<ii, vector<ii>, greater<ii>>pq;
	for(int i=1;i<=n;i++) {
		cin >> a[i];
		pq.push({-a[i], i});
	}
	int timeDiv = 0;
	while(!pq.empty()) {
		auto [u, i] = pq.top();pq.pop();
		u = -u;
		if(u == 1) {
			rmq[0][i] = timeDiv;
			continue;
		}
		timeDiv++;
		u /= divisor[u];
		if(u == 1) rmq[0][i] = timeDiv;
		else pq.push({-u, i});
	}
	initRMQ();
	while(q--) {
		int l, r;
		cin >> l >> r;
		int t = log2(r - l + 1);
		cout << max(rmq[t][l], rmq[t][r - (1 << t) + 1]) << nl;
	}
}
int main(){
	fast;
	indef();
	sieve();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}