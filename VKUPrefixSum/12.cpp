#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************

ll kanade(vector<ll> v){
    ll ans=0,sum=0;
    for(int i=0;i<(int)v.size();i++){
        sum+=v[i];
        if(sum % 9 ==0) ans++;
    }
    return ans;
}
void solve(){
    int n,m,ans=0;
    cin >> n >> m;
    vector<vector<ll>> a(n+5, vector<ll> (m+5,0));
    vector<vector<ll>> p(n+5, vector<ll> (m+5,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
        }   
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==1) p[i][j]=a[i][j];
            else p[i][j]=p[i][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++){
            vector<ll> v;
            for(int k=1;k<=n;k++){
                ll tmp;
                if(i==1) tmp=p[k][j];
                else tmp=p[k][j]- p[k][i - 1];
                v.pb(tmp);
            }
            ans+=kanade(v);
        }
    }
    cout << ans;
}
int main(){
    fast;
    indef();
    int tt=1;
    while(tt--) solve();
}