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
bool prime[35];
void sieve() {
	memset(prime, true, sizeof prime);
	prime[1] = false;
	for(int i = 2; i * i <= 30; i++) {
		if(prime[i]) {
			for(int j = i * i; j <= 30; j += i) {
				prime[j] = false;
			}
		}
	}
}
bool compare(pair<int,int> a, pair<int,int> b) {
	if(a.Y == b.Y) return a.X <= b.X;
	return a.Y <= b.Y;
}
void solve(int id){
	string s;cin >> s;
	vector<pair<int,int>> a;
	for(int i = 1; i <= 13; i++) {
		for(int j = 1; j <= (i == 13 ? 5 : 30); j++) {
			if(prime[i] && prime[j]) a.pb({i, j});
		}
	}
	// for(auto [x, y] : a) cout << y << ' ' << x << nl;
	sort(all(a));
	int k = a.size();
	int d = (s[0] - '0') * 10 + (s[1] - '0');
	int m = (s[3] - '0') * 10 + (s[4] - '0');
	int y = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
	
	int pos = lower_bound(all(a), make_pair(m, d)) - a.begin();
	auto before = a.back();
	int before_year = y - 1;

	if(pos > 0) {
		before = a[pos - 1];
		before_year++;
	}
	
	printf("%02d/%02d/%04d\n", before.second, before.first, before_year);
	

	pos = upper_bound(all(a), make_pair(m, d)) - a.begin();
	auto after = a[0];
	int after_year = y + 1;
	if(pos < a.size()) {
		after = a[pos];
		after_year--;
	}
	
	printf("%02d/%02d/%04d", after.second, after.first, after_year);

}
int main(){
	fast;
	indef();
	sieve();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}