#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(all(a));sort(rall(b));
    ll ans = 0;
    for(int i=0;i<n;i++) ans+=max(a[i],b[i]);
    cout << ans << nl;
}   
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();
}
