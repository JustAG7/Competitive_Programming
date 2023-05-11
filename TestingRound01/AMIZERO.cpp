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
	ll l,r,t,k;
	cin >> l >> r >> t >> k;
	if(k % t!=0 || k<t){
		cout << 0 << nl;
		return;
	}
	else{
		ll tmp=k/t,a,b;
		a=pow(10,tmp);
		b=pow(10,tmp+1);
		a=r/a-(l-1)/a;
		b=r/b-(l-1)/b;
		cout << a-b << nl;
	}
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}