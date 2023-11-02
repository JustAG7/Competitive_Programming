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
const int N = 1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};




void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}
int a[N];
bool dp[N];
void solve(){
	int n,k;
	cin >> n >> k;
	for(int i=0;i<k;i++) cin >> a[i];
	sort(a,a+k);
	// memset(dp,false,sizeof(dp));
	dp[0] = true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<k;j++){
			if(i >= a[j]){
				if(i - a[j] == 0) dp[i] = true;
				else if(!dp[i - a[j]]) dp[i] = true;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout << (dp[i] ? 'W' : 'L');
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}