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
const int N = 3e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[N];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(a,a+n);
	set<int> s;
	for(int i=0;i<n-1;i++){
		s.insert(a[i + 1] - a[i]);
	}
	vector<int> res;
	
	for(auto x : s) res.pb(x);
	int l = 0, r = res.size() - 1;
	int ans = res.back();
	while(l<=r){
		int m = (l + r)/2;
		int cnt = 0;
		for(int i=0;i<n-1;i++){
			if(a[i + 1] - a[i] <= res[m]){
				cnt++;
				i++;
			}
		}
		if(cnt >= k){
			ans = res[m];
			r = m - 1;
		}
		else l = m + 1;
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