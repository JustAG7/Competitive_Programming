// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


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
int month[] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

tuple<int, int, int> get(vector<int> &a) {
	int day = a[0] * 10 + a[1];
	int month = a[2] * 10 + a[3] ;
	int year = a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7] ;
	return {day, month, year};
}
bool check_year(int x) {
	if(x % 400 == 0) return true;
	if(x % 100 == 0) return false;
	return x % 4 == 0;
}
void solve(int id){
	vector<int> a(8);
	for(int i = 0; i < 8; i++) {
		char c; cin >> c;
		a[i] = c - '0';
	}
	sort(all(a));
	vector<tuple<int, int, int>> res;
	do {
		auto [d, m, y] = get(a);
		if(check_year(y)) month[2] = 29;
		if(1 <= m && m <= 12 && 1 <= d && d <= month[m] && y > 0) 
			res.pb({y, m, d});
		month[2] = 28;

	} while(next_permutation(all(a)));

	if(!res.size()) return printf("0\n"), void();
	sort(all(res));
	auto [y, m, d] = res[0];
	printf("%d %02d %02d %04d\n", res.size(), d, m, y);
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}