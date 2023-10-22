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
#define nl '\n'

const ll M=1e9+7;
const int N = 305;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

bool dp[N][N][N];
bool vis[N][N][N];
string s;
bool calc(int l,int r,int k1,int k2,int turn){
	if(vis[l][r][k1]){
		return dp[l][r][k1];
	}
	if(k1 == 0) return true;
	if(k2 == 0) return false;

	vis[l][r][k1] = true;
	if(!turn){
		if(!calc(l + 1, r, k1 - (s[l] == 'B'), k2, 1)) return dp[l][r][k1] = false;
		if(!calc(l, r - 1, k1 - (s[r] == 'B'), k2, 1)) return dp[l][r][k1] = false;		
		return dp[l][r][k1] = true;
	}
	else{
		if(calc(l + 1, r, k1 , k2 - (s[l] == 'B'), 0)) return dp[l][r][k1] =  true;
		if(calc(l, r - 1, k1 , k2 - (s[r] == 'B'), 0)) return dp[l][r][k1] = true;		
		return dp[l][r][k1] = false;
	}
}
void solve(){
	int n,k;
	cin >> n >> k;
	cin >> s;
	
	cout << (calc(0, n - 1, k, k, 0) ? "NO" : "YES") << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}