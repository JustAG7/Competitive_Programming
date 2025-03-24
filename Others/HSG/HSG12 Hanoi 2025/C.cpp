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
const int N = 1e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}
int a[N];
void solve(int id){
	int n, k, x;
	cin >> n >> k >> x;
	vector<int> mp(10, 0);
	int diff = 0, ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int l = 1, r = 1; r <= n; r++) {
		mp[a[r]]++;
		if(mp[a[r]] == 1) diff++;
		while(diff > k) {
			multiset<int> s;
			int res = 0;
			for(int j = 1; j <= 9; j++) {
				if(mp[j] > 0) s.insert(mp[j]);
			}
			int cnt = 0;
			for(auto x : s) {
				if(cnt >= diff - k) break;
				res += x;
				cnt++;
			}
			if(res <= x) break;
			mp[a[l]]--;
			if(mp[a[l]] == 0) diff--;
			l++;
		}
		ans = max(r - l + 1, ans);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	for(int t = 1; t <= tt; t++) solve(t);
}