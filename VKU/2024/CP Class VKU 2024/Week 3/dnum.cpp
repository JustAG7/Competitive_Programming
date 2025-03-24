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
int divisor[N];
void process() {
	for(int i=2;i<=N-5;i++){
		if(divisor[i]) continue;
		for(int j=i;j<=N-5;j+=i){
			divisor[j] = i;
		}
	}
}
void solve(){
	ll a, b;
	while(cin >> a >> b) {
		map<int,int> mp;
		while(a > 1) {
			mp[divisor[a]]++;
			a /= divisor[a];
		}
		while(b > 1) {
			mp[divisor[b]]--;
			b /= divisor[b];
		}
		int ans = 0;
		for(auto &[_, y] : mp) ans += abs(y);
		cout << ans << nl;
	}
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}