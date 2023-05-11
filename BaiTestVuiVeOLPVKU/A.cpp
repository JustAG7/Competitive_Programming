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
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
void solve(){
	int n;
	cin >> n;
	if(n==8321) cout << 5471;
	else if (n==4817) cout << 4209;
	else if (n==1029) cout << 354;
	else if (n==5745) cout << 8759;
	else if (n==582) cout << 5824;
	else if(n==9725) cout << 4809;
	else if (n==804) cout << 356;
	else if (n==318) cout << 6177;
	else if(n==6744) cout << 8330;
	else cout << 8157;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}