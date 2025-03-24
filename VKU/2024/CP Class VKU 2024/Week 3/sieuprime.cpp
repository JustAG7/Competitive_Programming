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


const int N = 1e7+5;
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
bool check(ll n){
    // credit to https://codeforces.com/blog/entry/54396
    if(n<2) return false;
    for(ll i=2;i*i*i<=n;++i) if(n%i==0) return false;
    for(int it=0;it<1e5;++it){
        ll i = rand()%(n-1)+1;
        if(__gcd(i,n)!=1) return false;
    }
    return true;
}

int getSize(ll n) {
    int ans = 0;
    while(n > 0) {
        ans++;
        n /= 10;
    }
    return ans;
}
void solve(){
    ll n; cin >> n;
    bool ok = true;
    int sz = getSize(n);
    ll temp = 1;
    for(int i=1;i<sz;i++) temp *= 10;
    while(n > 0) {
        if(!ok) break;
        n %= temp;
        if(n == 0) break;
        ok &= check(n);
        temp /= 10;
    }
    cout << (ok ? "YES" : "NO");
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
