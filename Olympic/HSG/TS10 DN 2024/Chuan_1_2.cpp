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

ii s(int n) {
    int a = 0, b = 0;
    while (n) {
        a += n % 10;
        n /= 10;
        if (n == 0) swap(a, b);
        b += n % 10;
        n /= 10;
    }
    return make_pair(b, a);
}

int count(int n) {
    int ans = 0;
    while (n != 0) {
        ans++;
        n /= 10;
    }
    return ans;
}
void solve(){
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = 1; i < 1e7; i++) {
        pair<int, int> x = s(i);
        int diff = x.X - x.Y;
        diff = 1 - diff;
        if (count(i) % 2 == 1) diff = -diff;
        if (diff >= 0 && diff <= 9)
            if (i * 10 + diff >= a && i * 10 + diff <= b)
                ans++;
    }
    cout << ans;
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}