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


const int M = 998244353;
const int N = 3e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};


void indef(){
	if(fopen("input.txt", "r")){
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);	
	}
}

ll factorial[N];
void calc(){

	factorial[1] = factorial[0] = 1;
	for(int i = 2;i <= N;i++){
		factorial[i] = (factorial[i - 1] * i) % M;
	}
}
void solve(){
	string s;
	cin >> s;
	int count = 0;
	ll ans = 1;
	for(ll l = 0, r = 0; l < s.size(); l = r){
		while(r < s.size() && s[l] == s[r]) r++;
		count += r - l - 1;
		(ans *= r - l) %= M;
	}	

	cout << count << ' ' << (ans * factorial[count])%M << nl;
}
int main(){
	fast;
	indef();
	calc();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}