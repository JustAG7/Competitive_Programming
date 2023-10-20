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
	if(k >= 10) k -= (k - 10) /2 *2;
	vector<int> a(n),b(m);
	ll sum = 0;
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	bool turn = false;
	while(k--){
		sort(all(a));sort(all(b));
		if(!turn){
			if(a[0] < b[m - 1]) swap(a[0],b[m - 1]);
		}
		else{
			if(b[0] < a[n - 1]) swap(b[0],a[n - 1]);
		}
		turn = !turn;
	}

	
	for(int i=0;i<n;i++) sum += a[i];
	cout << sum << nl;
	
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}