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
ll res[12][55][55][2];
vector<int> a;
ll dp(int pos, int even, int odd, int check){
    if(pos==a.size()){
        return ((even-odd)==1);
    }
    ll &ans = res[pos][even][odd][check];
    if(ans != -1) return ans;
    ans = 0;
    if(check){
        int nEven = 0, nOdd = 0;
        for(int i=0; i<=9; i++){
            if(pos % 2 == 0) nEven = i;
            else nOdd = i;
            ans += dp(pos + 1, even + nEven, odd + nOdd, 1);
        }
    }
    else{
        int nEven = 0, nOdd = 0;
        for(int i=0; i<a[pos]; i++){
            if(pos % 2 == 0) nEven  = i;
            else  nOdd = i;
            ans += dp(pos + 1, even + nEven, odd + nOdd, 1);
        }
        if(pos % 2 == 0)
            ans += dp(pos + 1, even + a[pos], odd, 0);
        else ans += dp(pos + 1, even, odd + a[pos], 0);
    }
    return ans;
}
ll calc(ll n){
	if(n == 0) return 0;
	a.clear();
	for(int i=0;i<10;i++){
		a.pb(n % 10);
		n /= 10;
	}
	reverse(all(a));
	memset(res, -1, sizeof res);
	return dp(0, 0, 0, 0);

}
void solve(){
	ll a, b;
	cin >> a >> b;
	cout << calc(b) - calc(a - 1);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}