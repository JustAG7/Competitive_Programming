#include <bits/stdc++.h>
using namespace std;

int a[105];
bool check(int c){
    int x = c;
    int y = a[c];
    int z = a[y];
    int w = a[z];
    return x == w;
}
void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    bool ok = false;
    for(int i=1;i<=n;i++){
        if(check(i)) ok = true;
    }
    cout << ((ok) ? "<3\n" : "</3\n");
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();
}
