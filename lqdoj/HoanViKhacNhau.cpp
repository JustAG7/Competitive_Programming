#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n;
	cin >> n;
	if(n%2==0){
        for(int i=n-1;i>=n/2;i--) cout << i << " ";
        for(int i=1;i<=n/2-1;i++) cout << i << " ";
        cout << n;
    }
    else{
        for(int i=n-1;i>=n/2+1;i--) cout << i << " ";
        cout << n << " ";
	    for(int i=1;i<=n/2;i++) cout << i << " ";
    }
}
int main(){
	indef();
	fast;
	int tt=1;
	while(tt--) solve();
}