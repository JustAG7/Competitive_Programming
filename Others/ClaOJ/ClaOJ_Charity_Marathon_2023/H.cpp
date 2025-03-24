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

const int M=1e9+7;
const int N = 1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[N];
int mp[N];
void solve(){
	int n;
	cin >> n;
	int mx = 0;
	int ans = 0;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		cout << mp[a[i]] << ' ' << i << ' ';
		if(mp[a[i]] && mx!=i) ans += i - mx + 1;
		if(mp[a[i+1]]) mx = max(mx,mp[a[i+1]]);
		cout << ans << nl;
		mp[a[i]] = i;
	}

	
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}