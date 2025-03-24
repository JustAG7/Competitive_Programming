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

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};




void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}


ll bit[N];
int a[N],b[N], last[N];
int par[N];
int n;
void update(int x,ll val,int ind){
	for(;x<N;x += x & (-x)){
		if(bit[x] < val){
			bit[x] = val;
			last[x] = ind;
		}
	}
}
pair<ll,int> query(int x){
	ll ans = 0, pos = 0;
	for(;x>0;x -= x & (-x)){
		if(ans < bit[x]){
			ans = bit[x];
			pos = last[x];
		}
	}
	return {ans, pos};
}
void solve(){
	cin >> n;
	ll sum = 0;int pos = 0;
	ll tempSum; int tempPos;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) cin >> b[i];
	for(int i=1;i<=n;i++){
		auto [tempSum, tempPos] = query(a[i] - 1);
		par[i] = tempPos;
		if(sum < tempSum + b[i]){
			sum = tempSum + b[i];
			pos = i;
		}
		update(a[i], tempSum + b[i], i);
	}
	vi trace;
    trace.pb(pos);
    while (par[pos] != 0) {
        pos = par[pos];
        trace.pb(pos);
    }
    reverse(all(trace));
    cout << trace.size() << nl;
    for (int x : trace) cout << x << ' ';
	// for(int i = 1; i <= n;i++) cout << trace[i] << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}