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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n + 3, 0), pre(n + 2, 1), suf(n + 2, 1);
	
	for(int i=1;i<=n;i++) cin >> a[i];
	pre[1] = 1;
	int val = __gcd(a[1], a[2]);
	bool ok = true;
	for(int i=2;i<=n;i++){
		int tmp = __gcd(a[i], a[i + 1]);
		if(val > tmp) ok = false;
		pre[i] = ok;
	}
	val = __gcd(a[n - 1], a[n]);
	suf[n] = 1;
	ok = true;
	for(int i=n-1;i>0;i--){
		int tmp = __gcd(a[i], a[i - 1]);
		if(tmp > val) ok = false;
		suf[i] = ok;
	}
	ok = false;
	for(int i=1;i<=n;i++){
		int x = __gcd(a[i - 1], a[i + 1]);
		bool check = true;
		if(i > 1){
			if(pre[i - 1])
		}

	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}