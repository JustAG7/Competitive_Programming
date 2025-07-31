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

string s;
tuple<bool, int, int> check(char x) {
    int n = s.size();
	int l = -1, r = -1, sum = 0, start = 0;
	int cntU = 0, cntI = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == x) {
            sum++;
            if (s[i] == 'U') cntU++;
            else cntI++;
        } else {
            sum -= 2;
            if (s[i] == 'I') cntI++;
            else cntU++;
        }

        if (sum >= 0 && cntU > 0 && cntI > 0) {
            l = start + 1;
            r = i + 1;
            return {true, l, r};
        }

        if (sum < 0 && cntI == 0 && cntU == 0) {
        	sum = 0;
            start = i + 1;
            cntU = 0;
            cntI = 0;
        }
    }

    return {false, -1, -1};
}
void solve(int id){
	cin >> s;
	auto [ok, l, r] = check('U');
	if(ok) return cout << "Yes " << l << ' ' << r << nl, void();
	auto [ok2, l2, r2] = check('I');
	if(ok2) return cout << "Yes " << l2 << ' ' << r2 << nl, void();
	cout << "No\n";
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
