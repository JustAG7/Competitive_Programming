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
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
void solve(){
	int n;
	cin >> n;
	vector<ll> a(n + 1),cnt(n+1,0),dp(n + 1,M);
	int tmp = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] < n) cnt[a[i]]++;
	}
	while(cnt[tmp]) tmp++;
	dp[tmp] = 0;
	for(ll i=tmp;i>=1;i--){
		for(ll j=0;j<i;j++){
			dp[j] = min(dp[j], dp[i] + i * cnt[j]);
		}
	}
	cout << dp[0] - tmp << nl;
	

}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}