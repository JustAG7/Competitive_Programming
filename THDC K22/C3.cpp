#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int sum = 0, ans = 0;
	if(0 < n && n < 21){
		for(int i=1;i<=n;i++){
			sum += i;
			ans += i * sum;
		}
		cout << ans;
	}
	else cout << "N";
}
int main(){
	solve();
}