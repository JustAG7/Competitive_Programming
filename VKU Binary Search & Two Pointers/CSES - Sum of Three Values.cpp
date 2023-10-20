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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 1e9+7;
const int N = 5e3+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
pair<ll,int> a[N];
void solve(){
	int n; ll x;
	cin >> n >> x;
	for(int i=0;i<n;i++){
		cin >> a[i].X;
		a[i].Y = i + 1;
	}
	sort(a,a+n);
	for(int i=0;i<n-2;i++){
		int k = i + 2;
		for(int j=i+1;j<n-1;j++){
			k = max(k,j+1);
			while(a[i].X + a[j].X + a[k].X < x && k < n) k++;
			if(a[i].X + a[j].X + a[k].X == x){
				cout << a[i].Y << ' ' << a[j].Y << ' ' << a[k].Y;
				return;
			}
			while(a[i].X + a[j].X + a[k].X > x && k > j + 1) k--;
		}
	}
	cout << "IMPOSSIBLE";
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}