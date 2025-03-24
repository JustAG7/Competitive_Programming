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

int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	vector<pair<int,int>> a(n);
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		if(y>0){
			a[i].X=x;
			a[i].Y=y;
		}
	}
	sort(all(a));
	vector<vector<int>> dp(a.size()+1,vector<int> (n+1,1e9));
	for(int i=0;i<=n;i++){
		dp[0][i]=0;
	}
	for(int i=0;i<a.size();i++){
		int x=a[i].X;
		int y=a[i].Y;
		for(int j=1;j<=n;j++){
			for(int k=y;k>=0;k--){
				int tmp=k*x;
				if(j>=tmp){
					dp[i][j]=min(dp[i][j],min(dp[i-1][j],dp[i-1][j-tmp]+k));
				}
			}
		}
	}
	for(int i=0;i<a.size();i++){
		for(int j=1;j<=n;j++){
			cout << dp[i][j] << ' ';
		}
		cout << nl;
	}
}