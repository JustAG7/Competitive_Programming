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
int a[N];
int cnt[N];
bool check[N];
void solve(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	vector<vector<int>> res;
	for(int i=1;i<=N-5;i++){
		if(!cnt[i] || check[i]) continue;
		vector<int> tmp;
		for(int j=i;j<=N-5;j*=2){
			if(cnt[j] && !check[j]){
				for(int k=0;k<cnt[j];k++){
					tmp.pb(j);
				}
			}
			check[j] = true;
		}
		res.pb(tmp);
	}
	cout << res.size() << nl;
	for(auto x : res){
		cout << x.size() << ' ';
		for(auto y : x) cout << y << ' ';
		cout << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}