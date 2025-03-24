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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n;
	cin >> n;
	int l,r;
	l=r=ceil(sqrt(n));
	int ans = (l-1)*r;
	while(ans>=n){
		l--;
		ans = (l-1)*r;
	}
	ans=(l-1)*(r+1);
	while(ans>=n){
		l--;
		r++;
		ans=(l-1)*(r+1);
	}
	cout << l << ' ' << r;
}
signed main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}