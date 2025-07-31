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
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
ll n, x, k;
string s;
namespace sub1 {
	bool check() {
		return k <= 1e6;
	}
	void calc() {
		int ans = 0;
		for(int i = 0, j = 0; i < k; i++, j++) {
			if(s[j % n] == 'L') x--;
			else x++;
			// cout << x << ' ';
			if(x == 0) {
				ans++;
				j = -1;
			}
		}
		cout << ans << ' ' << x << nl;
	}
}

namespace sub2 {
	bool check() {
		for(int i = 1; i < n; i++) 
			if(s[i] != s[0]) return false;
		return true;
	}
	void calc() {
		int ans = 0;
		if(s[0] == 'L') {
			if(x > 0 && x - k <= 0) ans++;
			x -= k;
		}
		else {
			if(x < 0 && x + k >= 0) ans++;
			x += k;
		}
		cout << ans << ' ' << x << nl;
	}
}
void solve(int id){
	cin >> n >> x >> k;
	cin >> s;
	if(sub2::check()) sub2::calc();
	else if(sub1::check()) sub1::calc();
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}