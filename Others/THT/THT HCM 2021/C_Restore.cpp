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
const int N = 1e5+5;
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
int n;
ll a[N];
vector<int> r[N];
bool cant[N];
void solve(){
	cin >> n;
	for(int i=1;i<=n;i++){
		string s;
		cin >> s;
		if(s == "?") cant[i] = true;
		else a[i] = stoll(s);
	}
	
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j += j & (-j)){
			if(i == j) continue;
			r[j].pb(i);
		}
	}
	
	for(int i=n;i>=1;i--){
		if(cant[i] || !r[i].size()) continue;
		int x = r[i][0];
		while(x >= r[i][r[i].size() - 1]){
			a[i] -= a[x];
			if(cant[x]) {
				cant[i] = true;
				break;
			}
			if(!r[x].size()) x = x - 1;
			else x = r[x][r[x].size() - 1] - 1;
		}		
	}
	for(int i=1;i<=n;i++){
		if(cant[i]) cout << "? ";
		else cout << a[i] << ' ';
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
