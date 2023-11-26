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
#define donetest cerr << "done\n";


const int M = 998244353;
const int N = 5e5+5;
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
	if(fopen("delta.inp", "r")){
		freopen("delta.inp","r",stdin);
		freopen("delta.out","w",stdout);	
	}
}
ll a[N];
ll fact[N];
void calc(){
	fact[0] = 1;
	for(ll i=1;i<=N-5;i++){
		fact[i] = (fact[i - 1] * 2) % M;
	}
}
void solve(){
	int n,k;
	cin >> n >> k;
	multiset<int> s;
	ll ans = 0;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int l=0,r=0;r<n;r++){
		s.insert(a[r]);
		while(*s.rbegin() - *s.begin() > k){
			s.erase(s.find(a[l]));
			l++;
		}
		ans += r - l + 1;
		ans %= M;
	}
	cout << ans << ' ';
	ans = 0;
	sort(a,a+n);
	ll tmp = 0;
	for(int l=0,r=0;r<n;r++){
		while(a[r] - a[l] > k) l++;
		ans += fact[r - l];
		ans %= M;
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	calc();
	int tt;
	cin >> tt;
	solve();
}