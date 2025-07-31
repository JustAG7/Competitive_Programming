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
const int N = 1e4+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "lapnen"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

bool mat[N][N];
bool check(int i, int j) {
	for(int k = 0; k < 4; k++) {
		int dx = i + moveX[k];
		int dy = j + moveY[k];

		if(mat[dx][dy] == 1) return false;
	}
	return mat[i][j] == 0;
}
void setPos(int i, int j) {
	for(int k = 0; k < 4; k++) {
		int dx = i + moveX[k];
		int dy = j + moveY[k];
		mat[dx][dy] = 1;	
	}
	mat[i][j] = 1;
}
void solve(int id){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for(int i = 2; i <= n - 1; i++) {
		for(int j = 2; j <= n - 1; j++) {
			if(check(i, j)) setPos(i, j);
		}
	}
	bool ok = true;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ok &= mat[i][j];
		}
	}
	cout << (ok ? "CO" : "KHONG");
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}