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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll a[N], pref[N];
int n; ll k;
bool check(int r){
	int l = 0;
	ll sum = 0;
	for(int l = 0;r<=n;r++,l++){
		sum = pref[r] - pref[l];
		if(sum > k) return false;
	}
	return true;
}
void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	int l = 0, r = n, ans = 0;
	while(l<=r){
		int m = l + (r - l + 1)/2;
		if(check(m)){
			l = m + 1;
			ans = m;
		}
		else r = m - 1;
	} 
	cout << (ans == 0 ? -1 : ans);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
