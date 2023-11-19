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

void indefJudge(){
	if(fopen("herding.in", "r")){
		freopen("herding.in","r",stdin);
		freopen("herding.out","w",stdout);	
	}
}
void solve(){
	vi a(3);
	for(int i=0;i<3;i++) cin >> a[i];
	sort(all(a));
	if(a[2] - a[0] == 2) cout << "0\n";
	else if(a[1] - a[0] == 2 || a[2] - a[1] == 2) cout << "1\n";
	else cout << "2\n";
	cout << max(a[2] - a[1], a[1] - a[0]) - 1;
}
int main(){
	fast;
	indefJudge();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}