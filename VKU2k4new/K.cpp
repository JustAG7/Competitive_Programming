#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const db PI=3.14159265359;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van

db Area(db a,db b, db c){
	db p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
void solve(){
	db x,y,u,v,r;
	cin >> x >> y >> u >> v >> r;
	db s1,s2,s;
	db diag=sqrt((x-u)*(x-u)+(y-v)*(y-v))/2;
	if(diag<=r) s=(abs(x-u)*abs(y-v));
	else{

	}
	cout << fixed << setprecision(15);
	cout << diag << nl;
	cout << s;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}