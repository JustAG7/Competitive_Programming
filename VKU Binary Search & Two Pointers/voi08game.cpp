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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


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
int a[N],b[N];
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	int ans = 2e9+10;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		int pos = lower_bound(a,a+n,0 - x) - a;
		if(pos >= n) pos = n - 1;
		if(pos > 0) ans = min(ans,abs(a[pos - 1] + x));
		ans = min(ans,abs(a[pos]+x));
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}