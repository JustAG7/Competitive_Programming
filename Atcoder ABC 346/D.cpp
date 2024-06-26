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
const int N = 2e5+5;
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

ll c[N], f0[N], f1[N], g0[N], g1[N];
void solve(){
	int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int i = 0; i < n; i++) {
        f0[i + 1] = f0[i];
        f1[i + 1] = f1[i];
        if (i % 2 == 0) {
            if (s[i] == '0') f1[i + 1] += c[i];
            else f0[i + 1] += c[i];
        }
        else {
            if (s[i] == '0') f0[i + 1] += c[i];
            else f1[i + 1] += c[i];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        g0[i] = g0[i + 1];
        g1[i] = g1[i + 1];
        if (i % 2 == 0) {
            if (s[i] == '0') g0[i] += c[i];
            else g1[i] += c[i];
        }
        else {
            if (s[i] == '0') g1[i] += c[i];
            else g0[i] += c[i];
        }
    }
    ll ans = inf;
    for (int i = 1; i < n; i++) ans = min(ans, f0[i] + g0[i]);
    for (int i = 1; i < n; i++) ans = min(ans, f1[i] + g1[i]);
    cout << ans << '\n';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}