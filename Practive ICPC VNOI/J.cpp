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
#define donetest cout << "done\n";


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
ll solve(string s){
	int n = s.size();
	ll ans = 0;
	// s = "$" + s;
	string icpc = "ICPC"; 
	vector<vector<ll>> dp(n + 5, vector<ll> (4,0));
	for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'I') dp[i][0] = 1;
        }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < 4; j++) {
            if (s[i - 1] == icpc[j]) {
                dp[i][j] = dp[i - 2][j - 1] + dp[i][j];
            }
            dp[i][j] += dp[i - 1][j];
        }
        dp[i][0] += dp[i - 1][0];
    }

	return dp[n][3];
	// donetest
	// return ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	string s;
	// cin >> tt;
	while(cin >> s){
		if(s == "$") break;
		cout << solve(s) << nl;
	}
}