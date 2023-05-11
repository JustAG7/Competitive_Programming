#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){

}
int main(){
	fast;
	indef();
	for(int i=1; ;i++){
		for(int j=1;j<i;i++){
			ll a,b;
			cout << "? " << i << " " << j << endl;
			cin >> a;
			cout << "? " << j << " " << i << endl;
			cin >> b;
			if(a==-1 || b==-1){cout << "! " << i-1 << endl;return 0;}
			if(a!=b) {cout << "! " << a+b << endl;return 0;}
		}
	}
}