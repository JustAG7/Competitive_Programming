#include<bits/stdc++.h>
using namespace std;


void solve(){
	double R;
	cin >> R;
	if(0 < R && R < 50){
		double ans = (double) 4 / 3;
		ans *= 3.14;
		ans *= (R * R * R);		
		cout << fixed << setprecision(2) << ans;
	}
	else cout << "N";
}
int main(){
	solve();
}