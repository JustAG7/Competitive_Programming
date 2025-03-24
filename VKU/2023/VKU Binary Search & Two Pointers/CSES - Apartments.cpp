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
const int N = 2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll a[N],b[N];
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	sort(a,a+n);sort(b,b+m);
	int l = 0, r = 0,ans = 0;
	while(l<n && r<m){
		if(a[l]-k<=b[r] && b[r]<=a[l]+k){
			ans++;
			l++;
			r++;
		}
		else if(a[l]>b[r]) r++;
		else l++;
	}
	cout << ans;

}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}