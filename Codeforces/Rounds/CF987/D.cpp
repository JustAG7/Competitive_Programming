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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(int id){
	int n;
	cin >> n;
	vector<int> a(n), pre(n), suf(n);
	vector<int> ans(n);
	for(int &x : a) cin >> x;
	pre[0] = a[0]; suf[n - 1] = a[n - 1];
	for(int i = 1; i < n; i++) pre[i] = max(pre[i - 1], a[i]);
	for(int i = n - 2; i >= 0; i--) suf[i] = min(suf[i + 1], a[i]);
	ans[n - 1] = pre[n - 1];
	for(int i = n - 2; i >= 0; i--) {
		if(pre[i] > suf[i + 1]) ans[i] = ans[i + 1];
		else ans[i] = pre[i];
	}
	for(int i = 0; i < n; i++) cout << ans[i] << ' ';
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}