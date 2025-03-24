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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
ll binaryPower(ll a, ll k, ll n)
{
    a = a % n;
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % n;
        a = (a * a) % n;
        k /= 2;
    }
    return res;
}

// Kiểm tra điều kiện thuật toán với a cố định
bool test(ll a, ll n, ll k, ll m)
{
    ll mod = binaryPower(a, m, n);
    if (mod == 1 || mod == n - 1)
            return true;
    for (int l = 1; l < k; ++l)
    {
        mod = (mod * mod) % n;
        if (mod == n - 1)
            return true;
    }
    return false;
}
bool RabinMiller(ll n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;
    if (n < 11)
        return false;

    ll k = 0, m = n - 1;
    while (m % 2 == 0)
    {
        m /= 2;
        k++;
    }

    const static int repeatTime = 3;
    for (int i = 0; i < repeatTime; ++i)
    {
        ll a = rand() % (n - 3) + 2;
        if (!test(a, n, k, m))
            return false;
    }
    return true;
}
bool checkSuperPrime(ll n) {
	while(n > 0) {
		if(!RabinMiller(n)) return false;
		n /= 10;
	}
	return true;
}
void solve(int id){
	ll n;
	cin >> n;
	for(ll x = n, y = n;;x--, y++){
		set<ll> s;
		// cout << x << ' ' << y << nl;
		if(x >= 1) if(checkSuperPrime(x)) s.insert(x);
		if(checkSuperPrime(y)) s.insert(y);
		if(s.size()) {
			for(ll c : s) cout << c << ' ';
			return;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}