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
int cnt[55];
void solve(){
	int n,m;
	cin >> n >> m;
	m--;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		cnt[x]++;
	}
	int ans = 0;

	for(int i=50;i>1;i--){
		if(!cnt[i]) continue;
		int amountSocket = cnt[i]*(i - 1);

		// cout << amountSocket << nl;
		if(amountSocket <= m){
			m -= amountSocket;
			ans += cnt[i];
		}
		else{
			int countSocket = m / (i - 1);
			ans += countSocket;
			if(countSocket*(i - 1) < m) ans++;
			m = 0;
		}

		if(m == 0) break;
	}
	cout << (m == 0 ? ans : -1);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}