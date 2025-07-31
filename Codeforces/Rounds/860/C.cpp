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
const int maxn=1e5+5;

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
	vector<pair<int,int>> a(n);
	vector<int> b(n),c(n);
	for(int i=0;i<n;i++){
		cin >> a[i].X >> a[i].Y;
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int x=a[i].X;
		int y=a[i].Y;
		for(int j=1;j<=sqrt(x);j++){
			if(x % j==0){
				if(y*j>y*(x/j)){
					b[i]=j;
				}
				else b[i]=x/j;
			}
		}
	}
	for(int i=0;i<n;i++){
		c[i]=a[i].Y*b[i];
	}
	for(int i=1;i<n;i++){
		if(c[i]!=c[i-1]) ans++;
	}
	cout << ans+1 << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}

