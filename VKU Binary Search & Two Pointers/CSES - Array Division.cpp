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
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[N];
int n,k;
bool check(ll mx){
	ll sum = 0;
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(a[i] > mx) return false;
		if(sum + a[i] > mx){
			sum = 0;
			cnt++;
		}
		sum += a[i];
	}
	cnt += (sum > 0);
	return cnt <= k;

}
void solve(){
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	ll l = 0, r = 1e18;
	while(l<r){
		ll m = (l + r)/2;
		if(check(m)){
			r = m;
		}
		else l = m + 1;
	}
	cout << l;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}