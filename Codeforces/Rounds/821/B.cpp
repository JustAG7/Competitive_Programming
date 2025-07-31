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

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,x,y;
	cin >> n >> x >> y;
	if(min(x,y)!=0) cout << -1;
	else{
		int tmp=max(x,y);
		if(tmp==0 || (n-1) % tmp) cout << -1;
		else{
			int curr=0;
			for(int i=0;i<n-1;i++){
				if(i % tmp==0) curr=i+2;
				cout << curr << " ";
			}
		}
	}
	cout << "\n";
	
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}