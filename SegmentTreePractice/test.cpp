#include<iostream>
#include<math.h>
using namespace std;

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

int main(){
	indef();
	double a,b,c,denta;
	// tim nghiem của ax^2+bx+c=0
	cin >> a >> b >> c;
	//TH chi co bx+c=0
	if(a==0){
		//TH chi co c=0
		if(b==0){
			//neu c=0 co nghia la 0=0 luon dung
			if(c==0){
				cout << "vo so nghiem";
			}
			//nguoc lai ko co nghiem
			else{
				cout << "vo nghiem";
			}
		}
		//TH bx+c=0
		else{
			cout << "x=" << -c/b;
		}
	}
	//Xet ax^2+bx+c (b=0 hay c=0 ko anh huong khi a=0)
	else{
		denta=b*b-(4*a*c);
		if(denta<0) cout << "vo nghiem";
		else if(denta==0) cout << "x1=x2=" << -b/2*a;
		else{
			cout << "x1=" << (-b-sqrt(denta))/2*a << '\n';
			cout << "x2=" << (-b+sqrt(denta))/2*a;
		}
	}
}