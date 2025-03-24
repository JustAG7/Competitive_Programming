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


const int M = 998244353;
const int N = 3e3+5;
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

pair<ll,ll> a[N];

void add(ll &a, ll b) {
	a += b;
	a += M;
	a %= M;
}

void mul(ll &a, ll b) {
	b %= M;
	a *= b;
	a %= M;
}

ll addition(ll a, ll b) {
	a %= M;
	b %= M;
	return ((a + b) % M + M) % M;
}
ll multiply(ll a, ll b) {
	b %= M;
	a %= M;
	return (a * b) % M;
}

void solve(int id){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second;
	}

	ll ans = 0;

	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++) cout << a[i].first << ' ';cout << nl;
	for(int i = 1; i <= n; i++) cout << a[i].second << ' ';cout << nl;

	for(int i = 1; i <= n - 2; i++) {
		int k = i + 2;
		map<ll, ll> mp1, mp2, mp3;
		ll sum1 = 0, sum2 = 0, sum3 = 0;
		for(int j = i + 1; j <= n - 1; j++) {
			k = max(k, j);
			while(a[i].first + a[j].first > a[k].first && k < n) {
				k++;
				ll tmp = a[k].first;
				add(sum1, tmp);
				add(sum2, multiply(tmp, tmp));
				add(sum3, multiply(tmp, (multiply(tmp, tmp))));
				(mp1[a[k].second] += tmp) %= M;
				(mp2[a[k].second] += multiply(tmp, tmp)) %= M;
				(mp3[a[k].second] += multiply(tmp, multiply(tmp, tmp))) %= M;
			}
			ll A = (a[i].first + a[j].first) % M;
			int y = a[j].second;
			int x = a[i].second;
			ll dist = k - j;
			if(a[i].second == a[j].second) {
				// d = 1
				add(ans, multiply(dist, addition(mp1[y], A)));

				// d = 2
				ll res = sum2;
				add(res, -mp2[y]);
				add(res, -mp2[x]);

				add(ans, multiply(dist, multiply(A, A)));
				add(ans, multiply(res, res));
				add(ans, multiply(2LL, multiply(res, A)));
			}

			else {

				// d == 3
				ll res = sum3;
				ll res2 = sum2;
				ll res1 = sum1;
				
				add(res, -mp3[x]);
				add(res, -mp3[y]);
				add(res2, -mp2[x]);
				add(res2, -mp2[y]);
				add(res1, -mp1[x]);
				add(res1, -mp1[y]);

				add(ans, res);
				add(ans, multiply(multiply(dist, A), multiply(A, A)));
				add(ans, multiply(multiply(3, res1), multiply(A, A)));
				add(ans, multiply(multiply(3, A), res2));

				cout << ans << nl;
				// cout << i << ' ' << j << ' ' << k << nl;
				// cout << dist << nl;
				// cout << x << ' ' << y << ' ' << A << ' ' << multiply(multiply(dist, A), multiply(A, A)) << nl;

				// d = 2
				
				res = sum2;
				add(res, -mp2[y]);
				add(res, -mp2[x]);

				add(ans, multiply(dist, multiply(A, A)));
				add(ans, res);
				add(ans, multiply(2LL, multiply(res, A)));
			}
			cout << i << ' ' << j << ' ' << k << nl;
			cout << ans << nl;
			add(sum1, -a[j + 1].first);
			add(sum2, -multiply(a[j + 1].first, a[j + 1].first));
			add(sum3, -multiply(a[j + 1].first, multiply(a[j + 1].first, a[j + 1].first)));
			mp1[a[j + 1].second] = addition(mp1[a[j + 1].second], -a[j + 1].first);
			mp2[a[j + 1].second] = addition(mp2[a[j + 1].second], -multiply(a[j + 1].first, a[j + 1].first));
			mp3[a[j + 1].second] = addition(mp3[a[j + 1].second], -multiply(a[j + 1].first, multiply(a[j + 1].first, a[j + 1].first)));
		}
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}