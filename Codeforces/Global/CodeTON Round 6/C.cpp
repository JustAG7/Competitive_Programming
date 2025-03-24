#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
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
	int n,k;
	cin >> n >> k;
	vector<vector<int>> a(k + 1);
	vector<int> ans(k + 1,0);
	for(int i=0;i<n;i++){
		int x;cin >> x;
		a[x].pb(i+1);
	}
	int low = INT_MAX, high = INT_MIN;
	for(int i=k;i>=1;i--){
		if(!a[i].size()) continue;
		for(int x : a[i]){
			low = min(low,x);
			high = max(high,x);
		}
		ans[i] = 2*(high - low + 1); 
	}

	for(int i=1;i<=k;i++) cout << ans[i] << ' ';
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}