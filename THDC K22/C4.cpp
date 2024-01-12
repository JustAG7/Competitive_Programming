#include<bits/stdc++.h>
using namespace std;

int getNum(int x,int n){
	int ans = x;
	for(int i=2;i<=n;i++){
		ans *= x;
	}
	return ans;
}
void solve(){
	int x,n;
	cin >> x >> n;
	if(0 < x && x <= n && 2 <= n && n <= 10){
		int ans = 0;
		for(int i=1;i<=n;i++){
			ans += getNum(x, i * 2);
		}
		cout << ans;
	}
	else cout << "N";
}
int main(){
	solve();
}