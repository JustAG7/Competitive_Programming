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
const int N = 2e6;
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
ll fact[N + 5], inv_fact[N + 5];

ll pm(ll a, ll b, ll M) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = (ans * a) % M;
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
void process() {
    fact[0] = inv_fact[0] = 1;
    for(int i = 1; i <= N; i++) {
        fact[i] = (fact[i - 1] * i) % M;
        inv_fact[i] = pm(fact[i], M - 2, M);
    }
}
ll Ckn(ll n, ll k) {
    if(k > n) return 0;
    return fact[n] * (inv_fact[k] % M * inv_fact[n - k] % M) % M;
}
void solve(int id) {
	map<char, int> mp;
	string s;
	cin >> s;
	for(auto &c : s) mp[c]++;
	ll ans = fact[s.size()];
	ll deno = 1;
	for(auto [_, x] : mp) {
		deno = (deno * fact[x]) % M;
	}
	cout << (ans * pm(deno, M - 2, M)) % M;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}	