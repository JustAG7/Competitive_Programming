#include<bits/stdc++.h>
using namespace std;


int gcd(int a,int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}
void solve(){
	int a,b;
	cin >> a >> b;
	if(a == 0 || b == 0) cout << "N";
	else cout << gcd(a, b);
}
int main(){
	solve();
}