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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	int res1=a,res2=a,ans=a;
	if(a==0){
		cout << 1 << nl;
		return;
	}
	if(b>c) swap(b,c);
	ans+=b*2;
	c-=b;
	if(a>=c){
		ans+=c;
		a-=c;
		ans+=min(a+1,d);
	}
	else{
		ans+=a+1;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}