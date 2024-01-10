#include<bits/stdc++.h>
using namespace std;

bool checkSNT(int n){
	for(int i=2;i*i<=n;i++){
		if(n % i == 0) return false;
	}
	return true;
}
void solve(){
	int n;
	cin >> n;
	int ans = -1;
	if(1 <= n && n <= 10){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				int x;cin >> x;
				if(j % 2 == 0){
					if(checkSNT(x)) ans = max(ans, x);
				}
			}
		}
		if(ans == -1) cout << "N";
		else cout << ans;
	}
	else cout << "N";
}
int main(){
	solve();
}