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
int a[N], b[N];
int ans, n;

bool check(int val){
	ans = 0;
	for(int i=n,j=n;i>=1;i--){
		while(j>=1 && b[j] - val > a[i]) j--;
		if(j <= 0 || (j > 0 && b[j] + val < a[i])){
			if(ans) return false;
			ans = a[i];
		}
		else j--;
	}
	if(!ans) ans = a[1];
	return true;
}
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	sort(a + 1, a + 1 + n);
	sort(b + 1, b + 1 + n);

	int l = 0, r = 1e9, diff = -1;
	while(l <= r){
		int m = (l + r)/2;
		if(check(m)){
			diff = m;
			r = m - 1;
		}
		else l = m + 1;
	}
	check(diff);
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}