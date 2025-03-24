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
const int N = 1e6+5;
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
int n, m, d;
int thuan = 0, an = 0;
void calcThuan() {
	int tmp = 0;
	for(int i=0;i<=n;i++) {
		if(a[i] == 1) tmp++;
		else tmp = 0;
		thuan = max(thuan, tmp);
	}
}
void calcAn() {
	int tmp = 0;
	for(int i=0;i<=n;i++) {
		if(a[i] == 0) tmp++;
		else tmp = 0;
		an = max(an, tmp);
	}
}
void solve(int id){
	int C;cin >> C;
	
	cin >> n >> m >> d;
	memset(a, -1, sizeof a);
	
	for(int i=1;i<=2*m;i++){
		int x;cin >> x;
		int type = i % 2 == 0 ? 0 : 1;
		if(x + d - 1 > n - 1) {
			if(i % 2 != 0) thuan++;
			else an++;
			continue;
		}
		bool ok = true;
		for(int j=max(x-1,0);j<=min(x+d,n-1);j++){
			if(a[j] == 1 - type) {
				ok = false;
				break;
			}
		}
		if(ok) for(int j=x;j<=x+d-1;j++) a[j] = type;
		
		else {
			if(i & 1) thuan++;
			else an++;
		}
	}
	if(C == 1) cout << thuan << ' ' << an;
	else {
		thuan = 0, an = 0;
		calcThuan(); calcAn();
		cout << thuan << ' ' << an << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}