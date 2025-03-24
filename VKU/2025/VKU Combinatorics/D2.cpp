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
const int N = 2e5;
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

ll a[N + 5], f[N + 5];
ll n;

void process() {
	for(int i = 2; i <= N; i++) {
		int res = i;
		f[i] += f[i - 1];
		while(res % 2 == 0) {
			f[i]++;
			res /= 2;
		}
	}
}
void solve(int id){
	cin >> n;
	for(int i = 0; i < n; i++) 
		cin >> a[i];
	
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		int res = f[n - 1] - (f[n - 1 - i] + f[i]);
		ans ^= 1LL * (res == 0) * a[i];
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}