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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> R(n + 1,0), P(n + 1,0), S(n + 1,0);
	s = "#" + s;
	for(int i=1;i<=n;i++){
		R[i] = R[i - 1] + (s[i] == 'R');
		S[i] = S[i - 1] + (s[i] == 'S');
		P[i] = P[i - 1] + (s[i] == 'P');
	}
	int ans = 0, cnt = 0;
	for(int k=2;k<=n;k++){
		int tmp = 0;
		for(int i=1;i<=n;i+=k){
			int r = min(i + k - 1, n);
			tmp += max({R[r] - R[i - 1], S[r] - S[i - 1], P[r] - P[i - 1]});
		}
		if(tmp >= cnt){
			ans = k;
			cnt = tmp;
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}