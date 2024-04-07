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
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

void solve(){
	ll a, b, c;
	cin >> a >> b >> c;
	ll cnt = __builtin_popcountll(c);
	for(int n00 = 0; n00 <= 60 - cnt;n00++){
		for(int n01 = 0; n01 <= cnt;n01++){
			int n10 = cnt - n01;
			int n11 = 60 - cnt - n00;
			if((n10 + n11 != a) || (n01 + n11 != b)) continue;
			ll x = 0, y = 0;
			for(int i=0;i<60;i++){
				if(c >> i & 1){
					if(n10 > 0){
						x |= 1LL << i;
						n10--;
					}
					else{
						y |= 1LL << i;
						n01--;
					}
				}
				else{
					if(n11 > 0){
						x |= 1LL << i;
						y |= 1LL << i;
						n11--;
					}
				}
			}
			cout << x << ' ' << y;
			return;
		}
	}
	cout << -1;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}