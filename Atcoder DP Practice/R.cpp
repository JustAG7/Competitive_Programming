#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define int long long
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
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

struct Matrix{
	vector<vi> data;
	int row() const {return data.size();}
	int col() const {return data[0].size();}

	auto & operator [] (int i) {return data[i];}

	const auto & operator [] (int i) const {return data[i];}

	Matrix() = default;
	Matrix(int r): data(r) {}
	Matrix(int r, int c): data(r, vector <int> (c)) { }

    Matrix(const vector <vector <int> > &d): data(d) {
        assert(d.size());
        int size = d[0].size();
        assert(size);
        for (auto x : d) assert(x.size() == size);
    }
    friend ostream & operator << (ostream &out, const Matrix &d) {
        for (auto x : d.data) {
            for (auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }
	static Matrix identity(ll n){
		Matrix a = Matrix(n, n);
		while(n--) a[n][n] = 1;
		return a;
	}

	Matrix operator * (const Matrix &b){
		Matrix a = *this;

		assert(a.col() == b.row());
		Matrix c(a.row(),b.col());
		for(int i=0;i<a.row();i++){
			for(int j=0;j<b.col();j++){
				for(int k=0;k<a.row();k++){
					(c[i][j] += (a[i][k] * b[k][j]) % M) %= M;
				}
			}
		}
		return c;
	}
	Matrix pow(ll exp){
		assert(row() == col());

		Matrix base = *this, ans = identity(row());
		for(; exp>0; exp >>= 1, base = base * base){
			if(exp & 1) ans = ans*base;
		}
		return ans;
	}
};
void solve(){
	int n;
	cin >> n;
	Matrix a(n),b(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin >> x;
			a.data[i].pb(x);
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;cin >> x;
			b.data[i].pb(x);
		}
	}
	ll ans = 0;
	Matrix res = a.pow(3);
	// cout << res;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(res.data[i][j] != b.data[i][j]){
				return cout << "NO\n",void();
			}
		}
	}
	cout << "YES\n";
}
signed main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}