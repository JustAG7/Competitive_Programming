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

using type = ll; 

struct Matrix { // template from VNOI
    vector <vector <type> > data;

    int row() const { return data.size(); }

    int col() const { return data[0].size(); }

    auto & operator [] (int i) { return data[i]; }

    const auto & operator[] (int i) const { return data[i]; }

    Matrix() = default;

    Matrix(int r, int c): data(r, vector <type> (c)) { }

    Matrix(const vector <vector <type> > &d): data(d) {

    }

    void init() {
    	for(int i = 0; i < data.size(); i++) {
    		for(int j = 0; j < data[0].size(); j++) {
    			data[i][j] = 0;
    		}
    	}
    }

    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }

    static Matrix identity(long long n) {
        Matrix a = Matrix(n, n);
        while (n--) a[n][n] = 1;
        return a;
    }

    Matrix operator * (const Matrix &b) {
        Matrix a = *this;

        assert(a.col() == b.row());

        Matrix c(a.row(), b.col());
        for (int i = 0; i < a.row(); ++i)
            for (int j = 0; j < b.col(); ++j)
                for (int k = 0; k < a.col(); ++k)
                    (c[i][j] += a[i][k] * b[k][j]) %= M;

        return c;
    }

    Matrix pow(long long exp) {

        assert(row() == col());

        Matrix base = *this, ans = identity(row());
        for (; exp > 0; exp >>= 1, base = base * base)
            if (exp & 1) ans = ans * base;
        return ans;
    }
};
ll n, k;
ll d[N], cnt[N];
void solve(int id){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
		cnt[d[i]]++;
	}

	Matrix mat = Matrix(101, 101);
	mat.init();
	for(int i = 0; i < 101; i++) {
		for(int j = 0; j < 101; j++) {
			if(j == 0 && i <= 1) mat.data[i][j] = 1;

			if(j == 1 && i > 0) mat.data[i][j] = cnt[i];
			
			if(j >= 2 && j - i == 1) mat.data[i][j] = 1;
		}
	}
	Matrix p = Matrix(101, 101);
	p.init();
	p.data[0][1] = 1;
	Matrix ans = p * mat.pow(k + 1);
	cout << ans[0][0] << nl;
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