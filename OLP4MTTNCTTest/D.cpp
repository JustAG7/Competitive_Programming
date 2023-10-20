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

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll a[maxn],st[16][maxn],n;
int findlog(int n){
    int cnt=0,tmp=1;
    while(tmp<n){
        cnt++;
        tmp*=2;
    }
    if(cnt==0) return 0;
    if(cnt==1) return 1;
    return cnt-1;
}
void proc(int LG){
    for (int i = 1; i <= n; ++i) st[0][i] = a[i];
    for (int j = 1; j <= LG; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = max(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}
ll query(int l,int r){
    int k = __lg(r - l + 1);
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}
void solve(){
	cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
	int lg = findlog(n);
    proc(lg);
    a[0]=0;
    ll best = INT_MIN, sum = INT_MIN, ans = INT_MIN;
    int l = 1, r = 1, curr = 1;
    for (int i = 1; i <= n; i++) {
        if (sum + a[i] < a[i]) {
            curr = i;
            sum = a[i];
        } else {
            sum += a[i];
        }

        if (best <= sum) {
            best = sum;
            l = curr;
            r = i;
            ans=max(ans,best-query(l,r));
        }
        
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
