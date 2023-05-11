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
#define allr(x) (x).rbegin(),(x).rend()
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
	ll n,c,d;
	cin >> n >> c >> d;
	vector<ll> a(n);

	for(int i=0;i<n;i++) cin >> a[i];	
	sort(allr(a));
	
	ll l=0,r=1e16;
	
	while(l<r){
		ll m = l + (r - l + 1) / 2;
		ll sum=0;
		for(int i=0;i<d;i++){
			if (i % m < n) {
				sum += a[i%m];
			}
		}
		if(sum>=c) l=m;
		else r=m-1;
	}
	if(l==0) cout << "Impossible";
	else if(l==1e16) cout << "Infinity";
	else cout << l-1;
	cout << nl;
}	
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}