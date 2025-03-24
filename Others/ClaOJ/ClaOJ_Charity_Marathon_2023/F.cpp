#include <bits/stdc++.h>
using namespace std;
#define db double
#define ll long long

const int N = 1e5+5;
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

db a[N][3];

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    indef();
    int n;
    cin >> n;
    db x,y,z;
    cin >> x >> y >> z;
    for(int i=1;i<=n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    
    db Ox,Oy,Oz;
    db radius;
    for(int i=1;i<=n;i++){
        db res = -1;
        bool ok = true;
        for(int j=1;j<=min(n,j+70);j++){
            if(i==j) continue;
            db tmpa = a[j][0] - a[i][0];
            db tmpb = a[j][1] - a[i][1];
            db tmpc = a[j][2] - a[i][2];
            db tmp = round(tmpa*tmpa + tmpb*tmpb + tmpc*tmpc);
            if(res == -1) res = tmp;
            else if(res != tmp){
                ok = false;
                break;
            }
        }
        if(ok) {
            Ox = a[i][0];
            Oy = a[i][1];
            Oz = a[i][2];
            radius = res;
            break;
        }
    }
    db dist = (x - Ox)*(x - Ox) + (y - Oy)*(y - Oy) + (z - Oz)*(z - Oz);
    cout << fixed << setprecision(2) << abs(sqrt(dist) - sqrt(radius));
    return 0;
}
