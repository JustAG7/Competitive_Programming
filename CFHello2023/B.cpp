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
	if(n ==3){
		cout << "NO" << nl;
		return;
	}
	cout << "YES" << nl;
	if(n & 1){
		int x=n/2;
		for(int i=0;i<n/2;i++){
			cout << 1-x << ' ' << x << ' ';
		}
		cout << 1-x;
	}
	else{
		for(int i=0;i<n/2;i++){
			cout << "1 -1 ";
		}
	}
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}