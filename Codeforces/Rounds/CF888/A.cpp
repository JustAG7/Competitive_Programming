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
	int n,m,k,h;
	cin >> n >> m >> k >> h;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		int diff = abs(a[i] - h);
		int cal = diff / k;
		if(cal*k == diff && diff <= (m-1)*k && diff!=0) ans++;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}