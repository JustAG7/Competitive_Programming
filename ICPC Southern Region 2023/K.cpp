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
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define rev(i,start,n) for(int (i)=(start);(i)>=(n);(i--))
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 5e4+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	#ifndef ONLINE_JUDGE
		if(fopen("input.txt", "r")){
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);	
		}
	#endif
}
int a[N];
int mxL[N],mxR[N];
void solve(){
	int n;
	cin >> n;
	rep(i,1,n+1) cin >> a[i];
	mxL[0] = 0;
	mxR[n+1] = 0;
	rep(i,2,n+1) mxL[i] = min(mxL[i - 1] + 1,a[i]);
	rev(i,n,1) mxR[i] = min(mxR[i + 1] + 1,a[i]);	
	int ans = 0;
	rep(i,1,n+1){
		ans = max(ans, min(mxL[i],mxR[i]));
	}
	cout << ans;
}
int main(){
	fast;
	// indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}