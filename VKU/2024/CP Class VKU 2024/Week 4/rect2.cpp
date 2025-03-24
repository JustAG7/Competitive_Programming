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
const int N = 5e5+5;
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

ll a[N], ans = 0, n, m;
void calc() {
	stack<int> s;
	for(int i=1;i<=n;i++){
		while(s.size() && a[s.top()] >= a[i]) {
			int cur = s.top();s.pop();
			ll width = s.size() ? i - s.top() - 1 : i;
			ans = max(ans, a[cur] * width);
		}
		s.push(i);
	}
	while(s.size()) {
		int cur = s.top();s.pop();
		ll width = s.size() ? n - s.top() - 1 : n;
		ans = max(ans, a[cur] * width);
	}
}
void solve(){
	cin >> m >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	calc();
	for(int i=1;i<=n;i++) a[i] = m - a[i];
	calc();
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}