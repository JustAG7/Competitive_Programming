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
	vector<int> a(n + 1, 0);
	vector<vector<int>> pre(n + 1, vector<int>(30, 0));
	for(int i=1;i<=n;i++){
		cin >> a[i];
		for(int j=0;j<30;j++){
			pre[i][j] = pre[i - 1][j];
			if(a[i] & (1 << j)) pre[i][j]++;
		}
	}
	int q;
	cin >> q;
	while(q--){
		int lt, k;
		cin >> lt >> k;
		int l = lt, r = n, ans = -1;
		while(l <= r){
			int m = (l + r)/2;
			int sum = 0;
			for(int i=0;i<30;i++){
				if(pre[m][i] - pre[lt - 1][i] == m - lt + 1){
					sum |= (1 << i);
				}
			}
			if(sum >= k){
				ans = m;
				l = m + 1;
			}
			else r = m - 1;
		}
		cout << ans << ' ';
	}
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}