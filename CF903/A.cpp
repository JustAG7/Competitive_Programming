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
	// #ifndef ONLINE_JUDGE
		if(fopen("input.txt", "r")){
			freopen("input.txt","r",stdin);
			freopen("output.txt","w",stdout);	
		}
	// #endif
}
void solve(){
	int n,m;
	cin >> n >> m;
	string a,b;
	cin >> a >> b;
	if(a.find(b) != ::string::npos){
		cout << "0\n";
		return;
	}
	for(int i = 1;i <= 6;i++){
		a += a;
		if(a.find(b) != ::string::npos){
			cout << i << nl;
			return;
		}
	}
	cout << "-1\n";
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}