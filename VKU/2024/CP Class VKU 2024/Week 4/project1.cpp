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


const int M = 1e9+7;
const int N = 4e5+5;
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
ll a[N], dp[N];
void solve(){
	int n;
	ll h, s, d;
	cin >> n;
	cin >> h >> s >> d;
	for(int i=1;i<=n;i++) cin >> a[i];
	ll ans = 0, employee = 0;
	stack<pair<ll,ll>> st;
	for(int i=1;i<=n;i++) {
		if(employee > a[i]) {
			ans += d * (employee - a[i]);
			st.push({i, employee - a[i]});
		}
		else if(a[i] > employee) {
			ll remain = a[i] - employee;	

			while(st.size()) {
				if(remain == 0) break;
				auto [cur, emp] = st.top(); st.pop();
				ll x = (i - cur) * s;
				ll y = h + d;
				ll used = min(emp, remain);
				emp -= used;
				if(x < y) {
					ans += x * used;
					ans -= d * used;
					remain -= used;
					st.push({cur, emp});
				}
				else {
					while(st.size()) st.pop();
					break;
				}
			}
			ans += remain * h;
			
		}
		ans += a[i] * s;
		employee = a[i];
	}

	cout << ans + employee * d;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}