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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
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
	int n,m,k;
	cin >> n >> m >> k;
	vector<vector<int>> a(n,vector<int> (n)),dp(n,vector<int> (n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> a[i][j];
		}
	}
	

}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}