#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const int M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(int a, int b, int c, int n) {
	if (n == 0) return;
	solve(a, c, b, n-1);
	cout << a << ' ' << c << nl;
	solve(b, a, c, n-1);
}

signed main(){
    fast;
    indef();
    int n;
    cin >> n;
    cout << (1 << n) - 1 << nl;
    solve(1, 2, 3, n);
}
