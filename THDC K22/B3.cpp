#include<bits/stdc++.h>
using namespace std;


void solve(){
	double a, b, c;
	cin >> a >> b >> c;
	if(a != b && b != c && a != c){
		if(a > b) swap(a, b);
		if(b > c) swap(b, c);
		if(a > b) swap(a, b);
		cout << b;
	}	
	else cout << "N";
}
int main(){
	solve();
}