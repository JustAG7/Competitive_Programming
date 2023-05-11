#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

char a[N][N];
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == '#') continue;
            int curr = 0;
            if (i < n - 1) curr ^= (a[i + 1][j] - '0');
            if (j < n - 1) curr ^= (a[i][j + 1] - '0');
            curr += (curr==0);
            ans ^= curr;
        }
    }
    cout << ((ans) ? "BACH\n" : "KHOA\n");

    
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    indef();
    int tt=1;
    cin >> tt;
    while (tt--) solve();

}
