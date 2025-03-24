#include<bits/stdc++.h>
using namespace std;

void Bres(int x1, int y1, int x2, int y2) {
    cout << "Bres\n";
    int deltaX = x2 - x1, deltaY = y2 - y1;
    int p = 2 * deltaY - deltaX;
    for(int x = x1, y = y1; x <= x2; x++) {
        cout << x << ' ' << y << endl;
        if(p >= 0) {
            y++;
            p += 2 * (deltaY - deltaX);
        }
        else p += 2 * deltaY;
    }
}
void Midpoint(int x1, int y1, int x2, int y2) {
    cout << "MP\n";
    int dx = x2 - x1, dy = y2 - y1;
    int p = dy - dx/2;
    for(int x = x1, y = y1; x <= x2; x++) {
        cout << x << ' ' << y << endl;
        if(p >= 0) {
            p += dy - dx;
            y++;
        }
        else p += dy;
    }
}
void putpixel(int x, int y) {
    // glBegin(GL_POINTS);
    // glVertex2i(x, y);
    // glEnd();
}
void circleBres(int xc, int yc, int r) {
    cout << "BRES CIRCLE\n";
    int x = 0, y = r;
    int p = 3 - 2 * r;
    while(x <= y) {
        cout << x << ' ' << y << endl;
        
        // putpixel(x, y, color);
        if(p >= 0) {
            y--;
            p += 4 * (x - y) + 10;
        }
        else p += 4 * x + 6;
        x++;
    }
}
void circleMP(int xc, int yc, int r) {
    cout << "MP CIRCLE\n";

    int x = 0, y = r;
    int p = 5 / 4 - r;
    while(x <= y) {
        cout << x << ' ' << y << endl;
        if(p >= 0) {
            y--;
            p += 2 * (x - y) + 5;
        }
        else p += 2 * x + 3;
        x++;
    }
}

void ElipBres(int xc,int yc, int a, int b){

    double x,y,p,x0, y0,a2,b2;
    a2=a*a; b2=b*b;
    x=0; y=b; 
    p= -2 * b + 2 * b2 / (a2) + 1;
    x0=a2/(sqrt(a2+b2));
    y0=b2/(sqrt(a2+b2));
    // - 2 * b + 1 + (2 * b^2 / a^2)
    // - 2 * a + 1 + (2 * a^2 / b^2)
    while (x<=x0){

        //4 * (1 - y) + 2 * b^2 * (2 * x + 3) / a ^ 2
        //4 * (1 - x) + 2 * a^2 * (2 * y + 3) / b ^ 2
        put4pixel(xc,yc,x,y);
        if (p<0) p+=2*b2*(2*x+3)/a2;
        else{

            p+=4*(1-y)+ 2*b2 * (2*x+3)/a2;
            y--;

        }
        x++;

    }
    x=a; y=0; p=2*a2/b2 - 2*a+1;
    while (y<=y0){

        put4pixel(xc,yc,x,y);
        if (p<0 ) p+=2*a2*(2*y+3)/b2;
        else{

            p+=4*(1-x) + 2*a2*(2*y+3)/b2;
            x--;

        }   
        y++;

    }

}

void ElipMidpoint(int xc, int yc, int a, int b, int color) {
    int x, y;
    float x0, y0, a2, b2, p;

    a2 = a * a;
    b2 = b * b;

    x0 = (int)(a2 / sqrt(a2 + b2));
    y0 = (int)(b2 / sqrt(a2 + b2));

    // b^2 - a^2 * b + (1 / 4) * a^2
    // a^2 - b^2 * a + (1 / 4) * b^2
    p = b2 - a2 * b + (1 / 4) * a2;
    x = 0;
    y = b;
    // (2 * x + 3) * b2 (- 2 * a^2 * (y - 1))
    while (x <= x0) {
        put4pixel(xc, yc, x, y, color);
        if (p < 0)
            p += (2 * x + 3) * b2;
        else {
            p += (2 * x + 3) * b2 - 2 * a2 * (y - 1);
            y--;
        }
        x++;
    }

    x = a;
    y = 0;
    p = a2 - a * b2 + (1 / 4) * b2;

    while (y <= y0) {
        put4pixel(xc, yc, x, y, color);
        if (p < 0)
            p += a2 * (2 * y + 3);
        else {
            p += (2 * y + 3) * a2 - 2 * b2 * (x - 1);
            x--;
        }
        y++;
    }
}
double BNK(double t, int k, int n)
{
    double b;
    b=CKN(n,k)*LT(1-t,n-k)*LT(t,k);
    return b;
}
Point   Tpt (Point  p[], int n, double t)
{
    Point  pt;
    double B;
    pt.x=0; pt.y=0;
    for (int k=0; k<=n; k++)
    {
        B=BNK(t,k,n);
        pt.x=(long)(pt.x+p[k].x*B);
        pt.y=(long)(pt.y+p[k].y*B);
    }
    return pt;
}
void veBezier(Point  p[], int n)

{
    float dt,t=0;
    int i;
    int m=10;
    Point  pt;
    dt=1/float(m);
    glBegin(GL_LINE_STRIP);
    for (i=1;i<=m;i++)
    {
        pt=Tpt(p,n,t);
        glVertex2i(pt.x,pt.y);
        t=t+dt; 
    }
    glVertex2i(p[n].x,p[n].y);
    glEnd();

}
void ClipCohen(Point A,Point B,Point wmin,Point wmax,int g){
    int thoat=0 , ve=1;
    double m;
    
    while(thoat==0){
        if((Ma(A)|Ma(B))==0)    thoat=1;    // A va B nam trong vung cn ma(A)=ma(B)=0000
        else if((Ma(A) & Ma(B))!=0)         // AB nam hoan toan ben ngoai vung cn
        {
            thoat =1;       ve=0;
        }else{
            if(Ma(A)==0)    HoanVi(&A,&B);  //A nam trong vung cn
            if(A.x==B.x)                    // A va B cung nam doc
            {
                if(A.y>wmax.y)  A.y=wmax.y; // 
                else A.y=wmin.y;
            }
            else 
            {
                m=(double)(B.y-A.y)/(B.x-A.x);
                if(A.x<wmin.x)
                {
                    A.y=A.y+(wmin.x-A.x)*m;
                    A.x=wmin.x;
                }else if(A.x>wmax.x)
                {
                    A.y=A.y+(wmax.x-A.x)*m;
                    A.x=wmax.x;
                }else if(A.y<wmin.y)
                {
                    A.x=A.x+(wmin.y-A.y)/m;
                    A.y=wmin.y;
                }else if(A.y>wmax.y)
                {
                    A.x=A.x+(wmax.y-A.y)/m;
                    A.y=wmax.y;
                }
            }

        }
    }
    if(ve) VeDuongThang(Xoay(A,g),Xoay(B,g));
}
// Xoay is cos -sin
//         sin  cos
void XenHinhNhiPhan(Point A,Point B,Point wmin,Point wmax,int g){
    Point P,Q,M;
    

    if((Ma(A)|Ma(B))==0) VeDuongThang(Xoay(A,g),Xoay(B,g));
    if((Ma(A)&Ma(B))!=0) return ;
    if((Ma(A)!=0) &&(Ma(B)==0)) HoanVi(&A,&B); // swap
    if((Ma(A)==0) &&(Ma(B)!=0)) 
    {
        P=A;Q=B;
        while((abs(P.x-Q.x)+abs(P.y-Q.y))>2)
        {
            M.x=(P.x+Q.x)/2;
            M.y=(P.y+Q.y)/2;
            if(Ma(M)==0)    P=M;
            else            Q=M;                
        }
        VeDuongThang(Xoay(A,g),Xoay(P,g));
    }
    if((Ma(A)!=0)&&(Ma(B)!=0)&&((Ma(A) & Ma(B))==0))
    {
        P=A;Q=B;
        M.x=(P.x+Q.x)/2;
        M.y=(P.y+Q.y)/2;

        while(( Ma(M)!=0) && ((abs(P.x-Q.x)+abs(P.y-Q.y))>2))
        {
            if((Ma(P)& Ma(M)) !=0)  P=M;
            else Q=M;
            M.x=(P.x+Q.x)/2;
            M.y=(P.y+Q.y)/2;            
        }
        if(Ma(M)==0)
        {
            XenHinhNhiPhan(P,M,wmin,wmax,g);
            XenHinhNhiPhan(M,Q,wmin,wmax,g);
        }
    }
}
int main(){
    fast;
    indef();
    Bres(1, 0, 6, 4);
}