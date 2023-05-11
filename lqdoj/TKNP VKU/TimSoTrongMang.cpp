#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,k;
	cin >> n >> k;
	vector<int> a(n),b(k);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<k;i++){
		int x;
		cin >> x;
		if(binary_search(all(a),x)) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}