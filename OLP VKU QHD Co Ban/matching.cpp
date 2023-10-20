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
const int N = 21;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
bool a[N][N];
ll dp[1 << N];
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	// (n & (1 << i)): get the iTh bit of n
	// (n & ~(1 << i)): set 0 to the iTh bit of n
	// (n | (1 << i)): set 1 to the iTh bit of n
	// (n ^ (1 << i)): set 0 to 1 or 1 to 0 to the iTh bit of n

	dp[0] = 1;
	for(int i=0;i<(1 << n);i++){
		int cnt = __builtin_popcount(i); // get number of 1 in bit
		for(int j=0;j<n;j++){
			if(a[cnt][j] && !(i & (1 << j))){ // if paired and the bit at pos j in i isn't 1
				(dp[i | (1 << j)] += dp[i]) %= M;
			}
		}
	}
	cout << dp[(1 << n) - 1];
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}