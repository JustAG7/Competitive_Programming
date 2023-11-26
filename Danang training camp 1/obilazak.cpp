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
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
void indef1(){
	if(fopen("obilazak.inp", "r")){
		freopen("obilazak.inp","r",stdin);
		freopen("obilazak.out","w",stdout);	
	}
}
int a[(1 << 10) + 5];
void solve(){
	int k;
	cin >> k;
	for(int i=1;i <= (1 << k);i++) cin >> a[i];
	vector<vector<int>> res;
	int cnt = 1;
	for(int i=1;i<=(1 << k) - 1;i*=2){
		cnt *= 2;
		vector<int> tmp;
		for(int j=i;j <= (1 << k);j+=cnt){
			tmp.pb(a[j]);
		}
		res.pb(tmp);
	}
	for(int i=res.size()-1;i>=0;i--){
		for(auto x : res[i]) cout << x << ' ';
		cout << nl;
	}
}
int main(){
	fast;
	indef1();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}