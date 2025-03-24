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
const int N = 2e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ii a[N];
map<ii,set<int>> mp;
void solve(){
	int n,q;
	cin >> n >> q;
	string s; cin >> s;
	mp[{0,0}].insert(0);
	int nx = 0, ny = 0;
	for(int i=0;i<n;i++){
		if(s[i] == 'U') ny++;
	    if(s[i] == 'D') ny--;
	    if(s[i] == 'L') nx--;
	    if(s[i] == 'R') nx++;
	    mp[{nx,ny}].insert(i + 1);
	    a[i + 1] = {nx, ny};
	}

	while(q--){
		int x,y,l,r;
		cin >> x >> y >> l >> r;
		if(mp.count({x, y})){
			auto &s = mp[{x, y}];
			if(mp[{x, y}].size() && (*mp[{x, y}].begin() < l || *--mp[{x, y}].end() >= r)){
				cout << "YES\n";
				continue;
			}
		}
		x = a[l - 1].X + a[r].X - x;
		y = a[l - 1].Y + a[r].Y - y;
		if(mp.count({x, y})){
			auto it = mp[{x, y}].lower_bound(l);
			if(it != mp[{x, y}].end() && *it <= r){
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}