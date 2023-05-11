#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define nl '\n'

const ll M=1e9+7;
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> b(n+1,vector<int> (n+1));
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin >> b[i][j];
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			a[i]+=(b[i][j]>b[0][0]);
		}
		for(int j=i+1;j<n;j++){
			a[i]+=(b[i][j]<b[0][0]);
		}
	}
	for(int &x : a) cout << x+1 << ' ';
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}