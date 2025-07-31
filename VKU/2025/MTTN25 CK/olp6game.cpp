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
const ll inf = 1e18;
const ll INF = 0x3f;
const ll sumCycle = 20;

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

ll p, k;
ll total(ll start, ll cycle) {
	return (start + cycle * sumCycle) * (k - 4 * cycle);
}
ll count(ll start, ll turn) {
	int l = 0, r = k / 4, pos = r;
	while(l <= r) {
		int m = (l + r) / 2;
		if(total(p, m) >= total(p, m - 1)) {
			pos = m;
			l = m + 1;
		}
		else r = m - 1;
	}
	ll ans = 0;
	for(int i = pos - 100; i <= pos + 100; i++) {
		if(0 <= i && i <= k / 4) {
			ans = max(ans, total(p, i));
		}
	}
	return ans;
}
ll calc() {
	if(p % 10 == 0) return p * k;
	if(p % 5 == 0) 
		return max(p * k, (p + 5) * (k - 1));
	
	ll ans = p * k;
	for(ll i = 0, num = p, turn = k; i < 10; i++) {
		ans = max(ans, num * turn);
		num += num % 10;
		turn--;
	}
	// 4, 8, 6, 2
	// 5, 0
	// 7, 4
	// 1, 2
	// 3, 6
	// 9, 8
	p += p % 10;
	k--;
	for(int i = 0; i < 4; i++) { 
		ans = max(ans, count(p, k));
		p += p % 10;
		k--;
	}
	
	return ans;
}
void solve(int id){
	cin >> p >> k;
	cout << calc() << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}