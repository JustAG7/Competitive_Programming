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
ll a[N];
void solve(){
	int n;ll s;
	cin >> n >> s;
	for(int i=0;i<n;i++) cin >> a[i];
	ll ans = 0,tmp = 0,sum = 0;
	int l = 0, r = 0;
	while(r<=n){
		while(sum > s && l < r){
			tmp--;
			sum-=a[l];
			l++;
		}
		ans -= tmp*(tmp - 1)/2;

		while(sum <= s && r<=n){
			tmp++;
			sum+=a[r];
			r++;
		}

		ans+= tmp*(tmp - 1)/2;
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