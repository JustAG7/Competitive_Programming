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
const int N = 1e7+5;
const ll inf = 1e13;
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
vector<ll> res = {6, 28, 496, 8128, 33550336, 8589869056, 137438691328};
int p[N];
vector<int> primes;

// Function to perform the Sieve of Eratosthenes
void sieve(int max_limit) {
    // Boolean array to mark prime numbers
    vector<bool> is_prime(max_limit + 1, true);
    
    // 0 and 1 are not primes
    is_prime[0] = is_prime[1] = false;
    
    // Sieve of Eratosthenes algorithm
    for (int i = 2; i * i <= max_limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_limit; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    // Insert all primes into the global vector
    for (int i = 2; i <= max_limit; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}
bool check(ll n) {
	if(n <= 1) return false;
	ll sum = 0;
	for(ll j = 1; j * j <= n; j++) {
		if(n % j == 0) {
			sum += j;
			if(n / j != j) sum += n / j;
		}
		if(n * 2 < sum) return false;
	}
	return n * 2 == sum;
}
void solve(int id){
	for(int i = 0; i < 10; i++) cout << primes[i] << ' ';cout << nl;
	for(auto k : res) {
		vector<ll> div;
		int cnt = 0;
		for(ll i = 2; i * i <= k; i++) {
			if(k % i == 0) {
				div.pb(i);
				while(k % i == 0) {
					k /= i;
					cnt++;
				}
			}
		}
		if(k > 1) div.pb(k);
		cout << cnt << ' ';
		for(auto x : div) cout << x << ' ';cout << nl;
	}
}
void process() {
	ll x = 1;
	for(int a = 0; a < 30; a++) {
		x *= primes[0];
		if(a % 2 == 0) continue;
		if(x < 0) break;
		for(int j = 1; j < primes.size(); j++) {
			ll y = primes[j];
			if(x * y < 0 || x * y > inf) break; 
				// cerr << x << ' ' << y << ' ' << x * y << nl;
			if (check(x * y)) {
				cerr << "found " << (x * y) << nl;
				cerr << "prime " << y << nl;
			}
		}
	}
	
}
int main(){
	fast;
	indef();
	sieve(1e7);
	process();
	int tt=1;

	// cin >> tt;
	// for(int t = 1; t <= tt; t++) solve(t);
}