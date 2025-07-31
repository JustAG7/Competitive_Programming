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
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	if(k == 1){ // 0 only
		cout << "1\n";
		return;
	}
	if(k == 2){
		if(m <= n) cout << m << nl; // write in paper and you'll see
		else cout << n + (m - n)/n << nl; // only if divisible by n can get k = 2
	}
	if(k == 3){ 
		if(m <= n) cout << "0\n"; // suit with k = 2
		else cout << m - n - (m - n)/n << nl; // must bigger than n and not divisible by n
	}
	if(k > 3) cout << "0\n"; // consider all case available, this never happen
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}