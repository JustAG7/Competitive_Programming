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
	vector<int> a(n);
	for(int &x : a) cin >> x;
	sort(all(a));
	a.erase(unique(all(a)), a.end());
	int m = a.size();
	int res = M;
	for(int i=0;i<m-1;i++){
		int tmp = a[i + 1] - a[i];
		if(tmp != 0) {
			res = min(res, tmp);
		}
	}
	set<int> s;
	for(int i=1;i*i<=res;i++){
		if(res % i == 0){
			s.insert(i);
			s.insert(res / i);
		}
	}
	vector<int> ans;
	for(auto x : s){
		if(x == 1) continue;
		bool ok = true;
		for(int i=0;i<m-1;i++){
			int tmp = a[i + 1] - a[i];
			// cerr << tmp << ' ' << x << nl;
			if(tmp % x != 0){
				ok = false;
				break;
			}
		}
		if(ok) ans.pb(x);
	}
	for(auto x : ans){
		cout << x << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}