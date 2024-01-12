#include<bits/stdc++.h>
using namespace std;


void solve(){
	int a,b;
	cin >> a >> b;
	if(-8 <= a && a <= 8 && -8 <= b && b <= 8){
		cout << (3 - a)*(3 - a) + (4 - b)*(4 - b);
	}
	else cout << "N";
}
int main(){	
	solve();
}