#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const db s = 100;
void solve(){
    db a,b,c,d;
    cin >> a >> b >> c >> d;
    db x = (90/a)*b;
    db y = (90/c)*d;
    if(x>=10) x = 90/a;
    else x = s/(a+b);
    if(y>=10) y = 90/c;
    else y = s/(c+d);
    if(x==y) cout << "Draw";
    else if(x<y) cout << "Megumin";
    else cout << "Yunyun";
    cout << nl;
}   
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();
}
