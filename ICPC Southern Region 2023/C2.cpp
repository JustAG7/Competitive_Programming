#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 1e3+5;

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

int n, k;
vii xy, xz, yz;
ll res = 0;
struct Point{
	int x,y,z;
};
Point a[N];


void solve(){
	// ip();
	ll n,k;
	set<ii> xy,yz,xz;
	cin >> n >> k;
	for(int i=0;i<k;i++){
		cin >> a[i].x >> a[i].y >> a[i].z;
		if(a[i].x == 0) yz.insert({a[i].y,a[i].z});
		else if(a[i].y == 0) xz.insert({a[i].x,a[i].z});
		else xy.insert({a[i].x,a[i].y});
		
	}
	ll ans = 0;
	set<tuple<int,int,int>> cross;

	ans +=  n * ((ll)xy.size());
	ans +=  n * ((ll)yz.size());
	ans +=  n * ((ll)xz.size());

	for(auto pxz : xz){
		for(auto pyz : yz){
			if(pxz.Y == pyz.Y){
				ans--;
				cross.insert({pxz.X,pyz.X,pxz.Y});
			}
		}
	}

	for(auto pxy : xy){
		for(auto pyz : yz){
			if(pxy.Y == pyz.X){
				ans--;
			}
		}
	}

	for(auto pxy : xy){
		for(auto pxz : xz){
			if(pxy.X == pxz.X){
				ans--;
				ans += cross.count({pxy.X,pxy.Y,pxz.Y});
			}
		}
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