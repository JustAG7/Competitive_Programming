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
const int N = 1e6+5;
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

const int LIM = 200;
vector<int> primes;

void sieve() {
    vector<bool> is_prime(LIM + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= LIM; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j <= LIM; j += i)
                is_prime[j] = false;
        }
    }
}

ll pm(ll a, ll b) {
	ll ans = 1;
	while(b) {
		if(b & 1) ans = (ans * a) % M;
		a = (a * a) % M;
		b /= 2;
	}
	return ans;
}

struct bigint {
	int cnt[205] = {0};

	bigint(ll n = 1) {
		for(int i = 2; i * i <= n; i++) {
			while(n % i == 0) {
				cnt[i]++;
				n /= i;
			}
		}
		if(n > 1) cnt[n] = 1;
	}

	const friend bigint operator * (const bigint &a, const bigint &b) {
		bigint ans;
		for(ll x : primes) {
			ans.cnt[x] = a.cnt[x] + b.cnt[x];
		}
		return ans;
	}

	const friend bigint operator / (const bigint &a, const bigint &b) {
		bigint ans;
		for(ll x : primes) {
			ans.cnt[x] = a.cnt[x] - b.cnt[x];
		}
		return ans;
	}

	ll calc() {
		ll ans = 1;
		for(ll x : primes) {
			ans = (ans * pm(x, cnt[x])) % M;
		}
		return ans;
	}
};

bigint fact[N];
void process() {
	sieve();
	fact[0] = bigint(1);
	for(int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * bigint(i);
	}
	cerr << "good\n";
}

ll Ckn(ll n, ll k) {
	bigint ans = fact[n];
	ans = ans / fact[k];
	ans = ans / fact[n - k];
	return ans.calc();
}
void solve(int id){
	ll n, k;
	cin >> n >> k;
	cout << Ckn(n - 1, k - 1) << nl;
}
int main(){
	fast;
	indef();
	process();
	int tt=1;
	cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}