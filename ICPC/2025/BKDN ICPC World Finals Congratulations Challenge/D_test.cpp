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
const int MAX = 31623;
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

bool prime[MAX];
vector<int> p;
void sieve() {
	memset(prime, true, sizeof prime);
	prime[1] = false;
	for(int i = 2; i * i <= MAX; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= MAX; j += i) {
				prime[j] = false;
			}
		}
	}
	for(int i = 2; i <= MAX; i++) {
		if(prime[i]) p.pb(i);
	}
}
int getDiv(int n) {
	int ans = 1;
	for(auto x : p) {
		if(n == 1 || x > n) break;
		if(n % x == 0) {
			int cnt = 0;
			while(n % x == 0) {
				n /= x;
				cnt++;
			}
			ans = ans * (cnt + 1);
		}
	}
	return ans;
}
void solve(int id){
	int l, r;
	cin >> l >> r;
	multiset<int> pq;
	for(int i = r; i >= l; i--) {
		int cnt = getDiv(i);
		if(pq.size() < 5) pq.insert(cnt);
		else if(*pq.begin() <= cnt) {
			if(*pq.rbegin() == cnt) break;
			pq.erase(pq.find(*pq.begin()));
			pq.insert(cnt);
		}
	}
	ll ans = 1;
	for(auto x : pq) ans *= x;
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	sieve();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}