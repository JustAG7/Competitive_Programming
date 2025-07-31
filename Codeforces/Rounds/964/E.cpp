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

ll res[N];
void process(){
	for(int i=1;i<=N-5;i++){
		int x = i;
		while(x > 0){
			x /= 3;
			res[i]++;
		}
		res[i] += res[i - 1];
	}
}
void solve(){
	int l, r;
	cin >> l >> r;
	ll ans = 0;
	int m = l;
	while(m > 0){
		m /= 3;
		ans++;
	}
	ans *= 2;
	ans += res[r] - res[l];
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}