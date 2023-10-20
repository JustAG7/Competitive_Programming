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

void ip(){
	cin >> n >> k;
	set<ii>sxy, syz, sxz;
	for(int i = 1; i <= k; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		if(x == 0){
			if(!syz.count({y, z})){
				yz.pb({y, z});
				syz.insert({y, z});
			}
		}
		if(y == 0){
			if(!sxz.count({x, z})){
				xz.pb({x, z});
				sxz.insert({x, z});
			}
		}
		if(z == 0){
			if(!sxy.count({x, y})){
				xy.pb({x, y});
				sxy.insert({x, y});
			}
		}
	}
	res += 1LL * sxy.size() * n;
	res += 1LL * syz.size() * n;
	res += 1LL * sxz.size() * n;
	set<tuple<int, int, int>> xyxz;

	for(ii pi : xy)
		for(ii pj : xz){
			if(pi.fi == pj.fi){
				res -= 1;
				xyxz.insert({pi.fi, pi.se, pj.se});
			}
		}

	for(ii pi : xy)
		for(ii pj : yz){
			if(pi.se == pj.fi){
				res -= 1;
			}
		}


	for(ii pi : xz)
		for(ii pj : yz){
			if(pi.se == pj.se){
				res -= 1;
				res += xyxz.count({pi.fi, pj.fi, pi.se});
			}
		}

    cout << res;
}

int main(){
	fast;
	// indef();
	int tt=1;
	// cin >> tt;
	// while(tt--) solve();
	while(tt--) ip();
}