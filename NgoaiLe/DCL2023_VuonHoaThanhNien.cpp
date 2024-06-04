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
    if(fopen(JA ".txt", "r")){
        freopen(JA ".txt","r",stdin);
        freopen("output.txt","w",stdout);  
    }
}

db r1, r2, h;
db a, b, c;
db eps = 1e-6;

pair<ll, db> calc(db length, db width, db height){
	db gap = ((r1 - r2) * height) / h;
	db len = (r1 * 4.0) + (r2 + gap) * 2.0 + width;
	ll cnt = (ll) len / length;
	db nLen = 1.0 * cnt * length;

	ll ans = cnt * 4;
	db vol = (db)4.0 * cnt * length * width * height;
	db remain = len - nLen;
	// cerr << "calc: " << gap << ' ' << len << ' ' << cnt << ' ' << remain << nl;
	if(remain <= 0) return {ans, vol};

	db totalRemain = remain * 4;
	ll remainBrick = totalRemain / length;
	if(totalRemain - length * remainBrick > 0) remainBrick++;
	ans += remainBrick;
	vol += remain * 4.0 * width * height;
	return {ans, vol};
}
void solve(){
	cin >> r1 >> r2 >> h;
	vector<db> a(3);
	for(int i=0;i<3;i++) cin >> a[i];
	ll ans = inf; db volume = inf;
	do{
		// cerr << "init : " << a[0] << ' ' << a[1] << ' ' << a[2] << nl;
		// cerr << "ans: ";
		auto [cnt, vol] = calc(a[0], a[1], a[2]);
		// cerr << cnt << ' ' << vol << nl;
		if(cnt < ans){
			ans = cnt;
			volume = min(volume, vol);
		}
		else if(cnt == ans){
			volume = min(volume, vol);
		}
	}
	while(next_permutation(all(a)));

	
	cout << ans << ' ';
	cout << fixed << setprecision(2) << volume;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}