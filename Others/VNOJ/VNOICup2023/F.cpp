#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl '\n'

/*
    this code is from Kuroni
    orz from the hardest problem in the contest
*/
void solve(){
    int n,k;
    ll cap;
    cin >> n >> cap >> k;
    ll off=0, zero=0;
    ll l=0,r=0;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        int a,s,c,b;
        cin >> a >> s >> c >> b;
        mp[s-off]+=a; mp[b-off]+=c;
        r+=a;l-=c;
        zero+=1LL*b*c;
        for(; r>cap;){
            auto [k,v] = *mp.rbegin();mp.erase(k);
            ll x =min(v,r-cap);
            r-=x;
            if((v-=x) > 0) mp[k]=v;
        }
        for(; l<0;){
            auto [k,v] = *mp.begin();mp.erase(k);
            ll x =min(v,-l);
            l+=x;
            zero-=1LL*x*(k+off);
            if((v-=x) > 0) mp[k]=v;
        }
        off+=k;
    }
    cout << zero << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) solve();
}
