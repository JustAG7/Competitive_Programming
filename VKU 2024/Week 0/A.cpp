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


const int M = 2e9;
const int N = 3e5+5;
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
map<int,int> mp;
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	ll ans = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	int mask = 1; 
	while(mask <= M){
		if(mask < 0) break;
		for(int i=0;i<a.size();i++){
			if(mask - a[i] < mask / 2) break;
			ll x = mp[mask - a[i]];
			ll y = mp[a[i]];
			if(mask - a[i] == a[i]) ans += x * (x - 1) / 2;
			else ans += x * y;
		}
		mask <<= 1;
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