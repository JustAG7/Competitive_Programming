#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
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

ll dp[105][N];
int a[105];

void solve(){
    int n, x;
    cin >> n >> x;
    
    // dp[i][j] = the number of ways to give j candies to i children  
    // this one is O(n * k) but it's WA 
    dp[0][0] = 1;
    
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    for(int i = 1; i <= n; i++){
        ll pref[x + 1];
        pref[0] = dp[i - 1][0];
        for(int j = 1;j <= x; j++){
        	pref[j] = (pref[j - 1] + dp[i - 1][j]) % M;
        }
        for(int j = 0; j <= x; j++){
        	ll tmp = pref[j];
        	if(j - a[i] - 1 >= 0){
        		tmp = (tmp - pref[j - a[i] - 1] + M) % M; 
        	}
        	dp[i][j] = tmp;
        }
    }
    
    cout << dp[n][x];
}

int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
    return 0;
}
