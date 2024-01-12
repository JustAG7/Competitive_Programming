#include<bits/stdc++.h>
using namespace std;


void solve(){
	int x;
	cin >> x;
	if(0 < x && x < 10){
		cout << 2*x*x - 3*x + 5;
	}
	else cout << "N";
}
int main(){
	solve();
}