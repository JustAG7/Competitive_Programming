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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M=1e9+7;
const int N = 1e7+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
int coeffs[] = {2,3,5,7};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int l,r;
	cin >> l >> r;
	if(l < r){
		r -= (r&1);
		if(r != 2) cout << r/2 << ' ' << r/2;
		else cout << -1;
		cout << nl;
		return;
	}
	else{
		for(int i=2;i<=sqrt(l);i++){
			int x = i;
			int y = l - x;
			if(__gcd(x,y) != 1){
				cout << x << ' ' << y << '\n';
				return;
			}
		}
		cout << "-1\n";
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}