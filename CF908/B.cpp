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
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}


void solve(){
	int n;
	cin >> n;
	vector<int> a(n),b(n,0);
	int cnt = 0;
	unordered_map<int,vi> mp;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]].pb(i);
	}

	for(auto x : mp){
		if(x.Y.size() >= 2){
			cnt++;
			if(cnt == 1){
				b[x.Y[0]] = 1;
				b[x.Y[1]] = 2;
			}
			if(cnt == 2){
				b[x.Y[0]] = 1;
				b[x.Y[1]] = 3;
			}
		}
		if(cnt == 2) break;
	}
	if(cnt < 2) return cout << "-1\n",void();
	for(int i=0;i<n;i++){
		if(!b[i]) cout << 1 << ' ';
		else cout << b[i] << ' ';
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