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
	string s;
	cin >> n >> s;
	
	if(n == 2){
		if(s[0] == s[1]) return cout << "RH\n", void();
		return cout << "NO\n", void();
	}
	bool ok = true;
	map<char, int> mp;
	for(auto c : s) mp[c]++;
	if(mp['W'] % 2 != mp['E'] % 2 || mp['S'] % 2 != mp['N'] % 2){
		return cout << "NO\n", void();
	}
	char x, y;
	if(mp['S'] > mp['N']) y = 'S';
	else y = 'N';
	if(mp['W'] > mp['E']) x = 'W';
	else x = 'E';

	int cntY = abs(mp['S'] - mp['N']) / 2;
	int cntX = abs(mp['W'] - mp['E']) / 2;

	vector<char> ans(n, 'R');
	for(int i=0;i<n;i++){
		if(s[i] == x && cntX > 0){
			ans[i] = 'H';
			cntX--;
		}	
		if(s[i] == y && cntY > 0){
			ans[i] = 'H';
			cntY--;
		}
	}
	for(auto c : ans) cout << c;
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}