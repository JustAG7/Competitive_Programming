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
#define dbg(x) cerr << (x) << ' ';


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
char a[1005][1005];
void solve(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
		}
	}
	
	int ans = 0;
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			map<char,int> mp;
			mp[a[i][j]]++;
			mp[a[j][n - i - 1]]++;
			mp[a[n - j - 1][i]]++;
			mp[a[n - i - 1][n - j - 1]]++;
			auto mx = mp.rbegin();
			if(mx->Y == 4) continue;
			char x = mx->X;
			for(auto q : mp){
				if(q.X == x) continue;
				ans += (x - q.X)*q.Y;
			}
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