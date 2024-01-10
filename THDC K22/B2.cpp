#include<bits/stdc++.h>
using namespace std;

void solve(){
	double a,b;
	cin >> a >> b;
	if(10 <= a && a <= 99 && 10 <= b && b <= 99){
		double avg = (a + b)/2;
		int number = avg;
		if(number % 2 == 0) cout << "E";
		else cout << "O";
	}
	else cout << 'N';
}
int main(){
	solve();
}