#include<bits/stdc++.h>
using namespace std;

void solve(){
	int a,b;
	cin >> a >> b;
	if(0 < a && a < 100 && 0 < b && b < 100){
		if(a % b == 0) cout << "T";
		else cout << "F";
	}
	else cout << "N";
}
int main(){
	solve();
}