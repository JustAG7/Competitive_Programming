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
const int N = 1e6+5;
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

bool check[N];
int par[N], digit[N];
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> res;
	queue<int> q;
	q.push(0);
	for(char c : s) {
		int lt = c - '0';
		res.pb(lt);
	}
	sort(all(res));
	while(!q.empty()) {
		int u = q.front();q.pop();
		for(auto v : res) {
			if(u == 0 && v == 0) continue;
			int num = (u * 10 + v) % n;
			if(check[num]) continue;
			check[num] = true;
			par[num] = u;
			digit[num] = v;
			q.push(num);
		}
	}

	if(!check[0]) cout << 0;
	else {
		vector<int> ans;
		for(int u = par[0]; u != 0; u = par[u]) {
			ans.pb(digit[u]);
		}
		reverse(all(ans));
		for(auto x : ans) cout << x;
		cout << digit[0];
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}