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
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
ll dp[N];
ll weight[1005];
int main(){
	fast;
    indef();
    int n;
    cin >> n;
    int ans = 1;
    memset(dp,M,sizeof(dp));
    dp[0] = -M;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        int pos = lower_bound(dp,dp+N,x) - dp;
        ans = max(ans,pos);
        dp[pos] = x;
    }
    cout << ans;
}
