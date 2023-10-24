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
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	
	for(int i=0;i<n;i++) cin >> a[i];
	if(k == 4){
		int cnt2 = 0;
		int ans = 2;
		for(int i=0;i<n;i++){
			if(a[i] % 4 == 0) return cout << "0\n", void();
			if(a[i] % 2 == 0) cnt2++;
			else ans = min(ans, k - a[i]%k);
		}
		cout << min(ans, max(0,2 - cnt2)) << nl;
	}
	else{
		int ans = k;
		for(int i=0;i<n;i++){
			if(a[i] % k == 0) return cout << "0\n", void();
			else ans = min(ans, k - a[i]%k);
		}
		cout << ans << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}