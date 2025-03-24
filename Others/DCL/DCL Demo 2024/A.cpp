#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
#define nl '\n'
#define vi vector<int>
#define vii vector<pair<int, int>>
#define dbgArr(a, index) for(int i=0; i<(index); i++) cerr << a[i] << ' ';
#define dbgMat(a, n, m) for(int i=0; i<(n); i++) {for(int j=0; j<(m); j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";

const int M = 1e9 + 7;
const int N = 3e5 + 5;
const long long inf = 1e18;
const long long INF = 0x3f3f3f3f3f3f3f3f;

void indef(){
    #define JA "input"
    if(fopen(JA ".inp", "r")){
        freopen(JA ".inp", "r", stdin);
        freopen(JA ".out", "w", stdout);    
    }
}

void solve(){
    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < n; i++){
        string t = "";
        int cnt = 1;
        char x = s[0];
        for(int j = 1; j < s.size(); j++){
            if(x != s[j]){
                t += to_string(cnt) + x;
                x = s[j];
                cnt = 1;
            }
            else cnt++;
        }
        t += to_string(cnt) + x;  
        s = t;
    }
    cout << s;
}

int main(){
    fast;
    indef();
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
