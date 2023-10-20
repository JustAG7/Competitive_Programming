#include <bits/stdc++.h>
using namespace std;
#define db long double
#define ll long long

const int N = 1e5+5;
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

db a[N][3];
db getDist(db a,db b,db c,db x,db y,db z){
    return sqrt((a-x)*(a-x) + (b-y)*(b-y) + (c-z)*(c-z));
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    indef();
    int n;
    cin >> n;
    db Nx,Ny,Nz;
    cin >> Nx >> Ny >> Nz;

    for(int i=1;i<=n;i++){
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }

    db x = 0,y = 0,z = 0;
    for(int i=1;i<=n-3;i++){
        db tmpx,tmpy,tmpz;
        db x1,y1,z1,d1;
        db x2,y2,z2,d2;
        db x3,y3,z3,d3;
        x1 = a[i+1][0] - a[i][0];
        y1 = a[i+1][1] - a[i][1];
        z1 = a[i+1][2] - a[i][2];
        tmpx = round(a[i+1][0] + a[i][0])/2;
        tmpy = round(a[i+1][1] + a[i][1])/2;
        tmpz = round(a[i+1][2] + a[i][2])/2;
        d1 = -(x1*(-tmpx) + y1*(-tmpy) + z1*(-tmpz));

        x2 = a[i+2][0] - a[i+1][0];
        y2 = a[i+2][1] - a[i+1][1];
        z2 = a[i+2][2] - a[i+1][2];
        tmpx = round(a[i+2][0] + a[i+1][0])/2;
        tmpy = round(a[i+2][1] + a[i+1][1])/2;
        tmpz = round(a[i+2][2] + a[i+1][2])/2;
        d2 = -(x2*(-tmpx) + y2*(-tmpy) + z2*(-tmpz));

        x3 = a[i+3][0] - a[i+2][0];
        y3 = a[i+3][1] - a[i+2][1];
        z3 = a[i+3][2] - a[i+2][2];
        tmpx = round(a[i+3][0] + a[i+2][0])/2;
        tmpy = round(a[i+3][1] + a[i+2][1])/2;
        tmpz = round(a[i+3][2] + a[i+2][2])/2;
        d3 = -(x3*(-tmpx) + y3*(-tmpy) + z3*(-tmpz));

        
        /*
            x1 y1 z1 = d1
            x2 y2 z2 = d2
            x3 y3 z3 = d3
        */
        db det,detA,detB,detC;
        det = round(x1*y2*z3 + y1*z2*x3 + z1*x2*y3 - z1*y2*x3 - y1*x2*z3 - x1*z2*y3);
        detA = round(d1*y2*z3 + y1*z2*d3 + z1*d2*y3 - z1*y2*d3 - y1*d2*z3 - d1*z2*y3);
        detB = round(x1*d2*z3 + d1*z2*x3 + z1*x2*d3 - z1*d2*x3 - d1*x2*z3 - x1*z2*d3);
        detC = round(x1*y2*d3 + y1*d2*x3 + d1*x2*y3 - d1*y2*x3 - y1*x2*d3 - x1*d2*y3);
        if(det == 0) continue;
        if(x == 0 && detA!=0) x = round(det/detA);
        if(y == 0 && detB!=0) y = round(det/detB);
        if(z == 0 && detC!=0) z = round(det/detC);
    }
    cout << fixed << setprecision(2) << abs(getDist(x,y,z,Nx,Ny,Nz) - getDist(x,y,z,a[4][0],a[4][1],a[4][2]));
}
