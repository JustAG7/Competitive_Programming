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


const int N = 3e5+5;
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
ll mul(ll a, ll b,ll M) {
    if (b == 0) return 0LL;
    if (b & 1) return (a + mul(a, b-1, M)) % M;
    ll tmp = mul(a, b/2, M);
    return (tmp + tmp) % M;
}
vector<vector<ll>> mulMat(vector<vector<ll>> a, vector<vector<ll>> b, ll M){
	vector<vector<ll>> c(a.size(), vector<ll> (b.size(), 0));
	for(int i=0;i<a.size();i++){
		for(int j=0;j<b.size();j++){
			for(int k=0;k<a.size();k++){
				(c[i][j] += mul(a[i][k], b[k][j], M) ) %= M;
			}
		}
	}
	return c;
}
vector<vector<ll>> powMat(ll b, ll M){
	vector<vector<ll>> ans = {{1, 0}, 
							  {0, 1}};
	vector<vector<ll>> a = {{1, 1}, 
							{1, 0}};
	while(b){
		if(b&1) ans = mulMat(ans, a, M);
		a = mulMat(a, a, M); 
		b /= 2;
	}
	return ans;
}

int main(){
	fast;
	indef();
	ll a,b,M;
	cin >> a >> b >> M;
	ll gcd = __gcd(a, b);
	auto ans = powMat(gcd, M);
	cout << ans[0][1] << nl;
}