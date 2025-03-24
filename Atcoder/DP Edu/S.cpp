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
const int N = 1e4+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

ll dp[N][105];
void add(ll &a, ll b){
	a += b;
	if(a >= M) a -= M;
}

void init(int l,int d){
	dp[l][0] = 1;
	for(int i=l-1;i>=0;i--){
		for(int j=0;j<d;j++){
			for(int k=0;k<10;k++){
				add(dp[i][j], dp[i + 1][(j + k) % d]);
			}
		}
	}
}

ll query(string s,int d){
	ll ans = 0; int carry = 0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<(s[i] - '0');j++)
			add(ans, dp[i + 1][(carry + j) % d]);
		carry = (carry + (s[i] - '0')) % d;
	}
	if(carry == 0) ans++;
	if(--ans < 0) ans += M;
	return ans;
}
void solve(){
	string s;
	int d;
	cin >> s >> d;
	init(s.size(), d);	
	cout << query(s, d);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}