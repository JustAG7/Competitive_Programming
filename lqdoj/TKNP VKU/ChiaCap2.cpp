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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    sort(all(a));

    int res = INT_MAX;
    for (int i = 0; i < k; ++i)
        res=min(res, a[n - k + i] - a[i]);

    cout << res;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
