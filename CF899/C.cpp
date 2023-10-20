#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
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
	int n;
	cin >> n;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	ll sum = 0;
	int start = 1;
	if(n == 1){
		cout << max(0LL,a[1]) << nl;
		return;
	}
	if(a[1] < 0){
		start = 3;
		sum = max(sum, a[1] + a[2]);
	}
	for(int i=start;i<=n;i++){
		if(a[i] > 0) sum+=a[i];
	}
	cout << sum << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}