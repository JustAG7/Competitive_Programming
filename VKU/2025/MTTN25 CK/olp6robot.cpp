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
const int N = 3e5+5;
const ll addition = 1e14;
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
ll n, x, k;
string s;
namespace sub1 {
	bool check() {
		return k <= 1e6;
	}
	void calc() {
		int ans = 0;
		for(int i = 0, j = 0; i < k; i++, j++) {
			if(s[j % n] == 'L') x--;
			else x++;
			// cout << x << ' ';
			if(x == 0) {
				ans++;
				j = -1;
			}
		}
		cout << ans << ' ' << x << nl;
	}
}

namespace sub2 {
	bool check() {
		for(int i = 1; i < n; i++) 
			if(s[i] != s[0]) return false;
		return true;
	}
	void calc() {
		int ans = 0;
		if(s[0] == 'L') {
			if(x > 0 && x - k <= 0) ans++;
			x -= k;
		}
		else {
			if(x < 0 && x + k >= 0) ans++;
			x += k;
		}
		cout << ans << ' ' << x << nl;
	}
}
namespace sub34 {
	vector<ll> pre, min_pre, max_pre;
	ll cross = 0;
	ll pos = inf, equal_pos = inf;
	
	
	void init() {
		cross = 0;
		pos = inf, equal_pos = inf;
		pre.assign(n + 5, 0);
		min_pre.assign(n + 5, M);
		max_pre.assign(n + 5, -M);
		pre[0] = (s[0] == 'L' ? -1 : 1);
		min_pre[0] = (s[0] == 'L' ? -1 : 1);
		max_pre[0] = (s[0] == 'L' ? -1 : 1);

		for(int i = 1; i < n; i++) {
			pre[i] = pre[i - 1] + (s[i] == 'L' ? -1 : 1);
			min_pre[i] = min(min_pre[i - 1], pre[i]);
			max_pre[i] = max(max_pre[i - 1], pre[i]);
			if(pre[i] == 0) pos = min(pos, 1LL * i);
		}
	}

	void answer() {
		cout << cross << ' ' << x << nl;
	}

	bool check(ll x, ll sum) {
		if(x <= 0) return x + sum >= 0;
		else return x + sum <= 0;
	}
	ll getCycle() {
		ll l = 0, r = 1e14, ans = 1e14;
		while(l <= r) {
			ll m = (l + r) / 2;
			ll sum = m * (pre[n - 1]);
			sum += x < 0 ? max_pre[n - 1] : min_pre[n - 1];

			if(check(x, sum)) {
				ans = m;
				r = m - 1;
			}
			else {
				if((x > 0 && pre[n - 1] > 0) || (x < 0 && pre[n - 1] < 0)) r = m - 1;
				else l = m + 1;
			}
		}
		return ans;
	}
	void calc() {
		init();
		
		ll numCycle = getCycle();
		// cout << "num cycle: " << numCycle << nl;
		for(int i = 0; i < n; i++) {
			// cerr << x + numCycle * pre[n - 1] + pre[i] << ' ';
			if(x + numCycle * pre[n - 1] + pre[i] == 0) {
				equal_pos = i;
				break;
			}
		} 

		ll numStep = numCycle * n + (equal_pos + 1); // first reach 0 steps
		// cout << numStep << nl;
		if(numStep > k || numStep < 0) {
			x += (k / n) * pre[n - 1];
			k -= n * (k / n);
			for(int i = 0; i < k; i++){
				x += (s[i] == 'L' ? -1 : 1);
			}
			return answer();
		}
		k -= numStep;
		x = 0;
		cross = 1;
		if(pos >= inf) {
			x += (k / n) * pre[n - 1];
			k -= n * (k / n);
		}
		else { 
			cross += k / (pos + 1);
			k -= (pos + 1) * (k / (pos + 1));
		}
		for(int i = 0; i < k; i++){
			x += (s[i] == 'L' ? -1 : 1);
		}
		
		answer();
	}
	

}
void solve(int id){
	// cout << "test " << id << nl;
	cin >> n >> x >> k;
	cin >> s;
	// cerr << "test: " << id << nl;
	if(sub2::check()) sub2::calc();
	else if(sub1::check()) sub1::calc();
	else sub34::calc();
	// cerr << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}