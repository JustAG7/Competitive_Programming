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


const int M = 1e9;
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

vector<int> sqr, cbr, res;
set<int> s1, c1, s5, s7;
int n;
bool checkSpecial(int n){ // check 4^k * (8 * m + 7)
    while(n % 4 == 0) n /= 4;
    n -= 7;
    return n % 8 == 0 && n >= 0;
}
void process(){
    for(int i=1;i*i<=M;i++){ // x^2
        sqr.pb(i * i);
        s1.insert(i * i);
    }
    for(int i=1;i*i*i<=M;i++){ // x^3
        cbr.pb(i * i * i);
        c1.insert(i * i * i);
    }
    for(int i=1;i*i*i*i*i<=M;i++){
        s5.insert(i * i * i * i * i); // x^5
    }
    for(int i=1;i*i*i*i*i*i*i<=M;i++){
        s7.insert(i * i * i * i * i * i * i); //x^7
    }


}

void solve(){
    cin >> n;
    int ans = 8;
    //single
    if(s1.find(n) != s1.end()) ans = min(ans, 2); // 2
    if(c1.find(n) != c1.end()) ans = min(ans, 3); // 3
    if(ans != 8) return cout << ans << nl, void();
    //pairs
    for(auto x : sqr){
        int y = n - x;
        if(y < 0) break;
        if(s1.find(y) != s1.end()) ans = min(ans, 4); // 2 2
        if(c1.find(y) != c1.end()) ans = min(ans, 5); // 2 3
    }
    if(ans != 8) return cout << ans << nl, void();
    if(s5.find(n) != s5.end()) return cout << 5 << nl, void(); // 5
    for(auto x : cbr){
        int y = n - x;
        if(y < 0) break;
        if(s1.find(y) != s1.end()) ans = min(ans, 5); // 3 2
        if(c1.find(y) != c1.end()) ans = min(ans, 6); // 3 3
    }
    if(ans != 8) return cout << ans << nl, void();

    if(!checkSpecial(n)) return cout << 6 << nl, void(); // 2 2 2
    //triplets
    for(auto x : sqr){
        for(auto y : cbr){
            int z = n - x - y;
            if(z < 0) break;
            if(s1.find(z) != s1.end()){
                return cout << 7 << nl, void(); // 2 3 2
            }
        }
    }

    for(auto x : s5){
        int z =  n - x;
        if(z < 0) break;
        if(s1.find(z) != s1.end()) return cout << 7 << nl, void(); // 2 5
    }
    if(s7.find(n) != s7.end()) return cout << 7 << nl, void(); // 7

    cout << 8 << nl; // 2 2 2 2

}
int main(){
    fast;
    indef();
    process();
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
