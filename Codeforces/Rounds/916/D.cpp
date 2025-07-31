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

void solve(){
	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n);
	set<ii> sa,sb,sc;
	for(int i=0;i<n;i++){
		cin >> a[i];
		sa.insert({a[i],i});
	}
	for(int i=0;i<n;i++){
		cin >> b[i];
		sb.insert({b[i],i});
	}
	for(int i=0;i<n;i++){
		cin >> c[i];
		sc.insert({c[i],i});
	}
	int ans = 0;
	// auto mx = *sb.rbegin();
	for(int i=0;i<n;i++){
		int tmp;

		sb.erase({b[i],i});
		sc.erase({c[i],i});
		
		auto mx = *sb.rbegin();
		auto my = *sc.rbegin();

		if(mx.Y == my.Y){
			auto mxx = *(++sb.rbegin());
			auto myy = *(++sc.rbegin());
			tmp = max(mx.X + myy.X, my.X + mxx.X);
			ans = max(ans, tmp + a[i]);
		}
		else ans = max(ans, a[i] + mx.X + my.X);


		sb.insert({b[i], i});
		sc.insert({c[i], i});
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}