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
/*
	https://cses.fi/problemset/task/2413
	Counting Towers
*/
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
ll dp[N][3];
void calc(){
	dp[1][1] = dp[1][2] = 1;
	for(int i=2;i<N;i++){
		dp[i][1] = (2 * dp[i - 1][1] + dp[i - 1][2]) % M;
		dp[i][2] = (4 * dp[i - 1][2] + dp[i - 1][1]) % M;
	}
}
int main(){
	fast;
	indef();
	calc();
	int tt=1;
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		cout << (dp[n][1] + dp[n][2])%M << nl;
	}
}