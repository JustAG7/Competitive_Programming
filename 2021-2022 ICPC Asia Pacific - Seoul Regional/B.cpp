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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int used[N];
int mp[N];
int a[N];
void solve(){
	int n,k;
	cin >> n >> k;
	int ans = M;
	for(int i=0;i<n;i++){
		cin >> a[i];
		used[a[i]]++;
	}
	int cnt = 0;
	for(int l=0,r=0;r<n;r++){
		mp[a[r]]++;
		if(mp[a[r]] == 1) cnt++;
		while(cnt == k){
			bool ok = true;
			for(int i=1;i<=k;i++){
				if(used[i] - mp[i] == 0){
					ok = false;
					break;
				}
			}
			if(ok) ans = min(ans,r - l + 1);
			mp[a[l]]--;
			if(mp[a[l]] == 0) cnt--;
			l++;
		}
	}
	cout << (ans == M ? 0 : ans);
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}