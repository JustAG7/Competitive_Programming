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
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,k,x,y;
	cin >> n >> k >> x >> y;
	vector<pair<ll,ll>> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i].X >> a[i].Y;

	auto dist = [&](ll x,ll y){
		return abs(a[x].X - a[y].X) + abs(a[x].Y - a[y].Y);
	};
	ll ans = dist(x,y);
	ll one = 1e18, two = 1e18;
	for(int i=1;i<=k;i++){
		one = min(one,dist(x,i));
		two = min(two,dist(y,i));
	}
	cout << min(ans, one + two) << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}