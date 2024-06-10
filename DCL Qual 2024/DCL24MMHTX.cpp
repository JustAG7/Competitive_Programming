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
int cnt0 = 1, cnt1 = 1;
int l = 1, r = 0;
int sz = 2;	
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
		if(s[i - 1] == 'L'){
			if(i & 1){
				l = 1;
				sz++;
				if(l == r){
					cnt1 = sz;
					cnt0 = 0;
				}
				else cnt1++;
			}
			else{
				l = 0;
				sz++;
				if(l == r){
					cnt0 = sz;
					cnt1 = 0;
				}
				else cnt0++;
			}
		}
		else{
			if(i & 1){
				r = 1;
				sz++;
				if(l == r){
					cnt1 = sz;
					cnt0 = 0;
				}
				else cnt1++;
			}
			else{
				r = 0;
				sz++;
				if(l == r){
					cnt0 = sz;
					cnt1 = 0;
				}
				else cnt0++;
			}
		}
	}
	cout << cnt1 << ' ' << cnt0;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}