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
bool a[1005], res[1005];
int n;
string s = "10110";
bool askFlip(int mid){
	cout << "? ";
	for(int i=1;i<=n;i++){
		if(i <= mid) cout << !a[i];
		else cout << a[i];
	}
	cout << endl;
	fflush(stdout);
	int coin; cin >> coin;
	return coin;
}
bool ask1(int pos){
	cout << "? ";
	for(int i=1;i<=n;i++){
		if(i == pos) cout << !a[i];
		else cout << a[i];
	}
	cout << endl;
	fflush(stdout);
	int coin; cin >> coin;
	return coin;
}
void solve(){
	// cout << "  101" << nl;
	cin >> n;
	if(askFlip(0)){
		for(int i=1;i<=n;i++) a[i] = !a[i];
	}
	
	int l = 0, r = n;
	while(l + 1 < r){
		int mid = (l + r)/2;
		if(askFlip(mid)) r = mid;
		else l = mid;
	}

	for(int i=1;i<=l;i++){
		a[i] = !a[i];
	}
	for(int i=1;i<=n;i++){
		if(ask1(i)) res[i] = !a[i];
		else res[i] = a[i];
	}
	cout << "! ";
	for(int i=1;i<=n;i++) cout << !res[i];
	
	cout << endl;
	fflush(stdout);

	// int x; cin >> x;
}
int main(){
	fast;
	// indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}