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
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
struct project{
	ll start,finish,reward;
};
bool cmp(project p1,project p2){
	return p1.finish < p2.finish;
}
project a[N];
ll dp[N];
int findPos(int pos){
	int l = 0, r = pos - 1;
	while(l<=r){
		int m = (l + r) / 2;
		if(a[m].finish < a[pos].start){
			if(a[m+1].finish < a[pos].start) l = m + 1;
			else return m;
		}
		else r = m - 1;
	}
	return -1;
}
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i].start >> a[i].finish >> a[i].reward;
	}

	sort(a,a+n,cmp);
	dp[0] = a[0].reward;
	for(int i=1;i<n;i++){
		ll temp = a[i].reward;
		int pos = findPos(i);
		if(pos != -1) temp += dp[pos];
		dp[i] = max(dp[i-1],temp);
	}
	cout << dp[n-1];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}	