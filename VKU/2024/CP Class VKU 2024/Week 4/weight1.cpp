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
const int N = 4e5+5;
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
ll a[N], n;
ll left_max[N], left_min[N];
ll right_max[N], right_min[N];

void calc_max() {
	stack<int> s, st;
	for(int i=0;i<n;i++) {
		while(s.size() && a[s.top()] < a[i]) {
			right_max[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()) s.pop();
	for(int i=n-1;i>=0;i--) {
		while(s.size() && a[s.top()] <= a[i]) {
			left_max[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
}
void calc_min() {
	stack<int> s, st;
	for(int i=0;i<n;i++) {
		while(s.size() && a[s.top()] > a[i]) {
			right_min[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while(s.size()) s.pop();
	for(int i=n-1;i>=0;i--) {
		while(s.size() && a[s.top()] >= a[i]) {
			left_min[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
}
void solve(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) {
		left_min[i] = -1;
		left_max[i] = -1;
		right_max[i] = n;
		right_min[i] = n;
	}
	calc_max();
	calc_min();
	ll ans = 0;
	for(int i=0;i<n;i++){
		ll x = (i - left_max[i]) * (right_max[i] - i);
		ll y = (i - left_min[i]) * (right_min[i] - i);
		ans += a[i] * (x - y);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}