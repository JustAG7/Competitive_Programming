#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct val{
 ll index;
 ll value;
};
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve() {
	 ll n,x;
	 cin >> n >> x;
	val a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i].value;
		a[i].index = i;
	}
	sort(a,a+n, [](val x, val y){
			return x.value <= y.value;
	});

	ll l = 0, r = n-1, mid = 1;
	while (l+1<r){
		while (a[l].value + a[r].value >= x && l+1 < r) r--;
		ll c = x - a[l].value - a[r].value;
		mid=l+1;
		while(a[mid].value<c && mid < r-1) mid++;
		if(a[mid].value==c){
			cout << a[l].index+1 << ' ' << a[mid].index+1 << ' ' << a[r].index+1;
			return;
		}
		r=n-1;
		l++;
	}

	cout << "IMPOSSIBLE";


}

int main() {
	indef();
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
