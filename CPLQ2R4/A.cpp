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
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
void solve(){
	int n,m;
	cin >> n >> m;
	vector<vector<int>> a(n+1,vector<int> (m+1,0));
	vector<vector<int>> ans(n+1,vector<int> (m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> a[i][j];
			a[i][j]+=a[i-1][j];
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
		}
	}
	*/
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout << a[i][j] << ' ';
		}
		cout << nl;
	}
	

}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}