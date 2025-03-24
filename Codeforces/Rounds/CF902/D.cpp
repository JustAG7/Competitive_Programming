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
#define dbg(x) cerr << (x) << ' ';


const int M = 998244353;
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
ll a[N];
ll mx[N];
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i) mx[i] = max(mx[i], a[j]);
	}
	sort(mx+1,mx+1+n);
	// after distinct element i found out that 
	// the ith maximum value will appear 2^i with (0 <= i < n)
	ll ans = 0, curr = 1;
	for(int i=1;i<=n;i++){
		(ans += mx[i]*curr) %= M;
		(curr *= 2) %= M;
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}