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
void update(int u,vector<int> &bit, int v,int n){
	for(;u <= n;u += (u & (-u))){
		bit[u] += v;
	}
}

ll query(vector<int> &bit,int v,int u){
	ll ans = 0;
	for(;u >= v;u -= (u & (-u))){
		ans += bit[u];
	}
	return ans;
}
void solve(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n + 1,0),bit(n + 1, 0);
	int left = M, right = 0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i] == 1){
			left = min(left, i);
			right = max(right, i);
		}
		update(i,bit,a[i],n);
	}
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int u;cin >> u;
			ll tmp = query(bit,left,right);

			cout << (tmp >= u? "YES\n" : "NO\n"); 
		}
		else{
			int i,c;
			cin >> i >> c;
			update(i,bit,-a[i]+c,n);
			a[i] = c;
			left = 0, right = n;
			for(int i=1;i<=n;i++) if(a[i] == 1) {left = i + 1; break;}
			for(int i=n;i>=1;i--) if(a[i] == 1) {right = i - 1; break;}
		}
	}

}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}