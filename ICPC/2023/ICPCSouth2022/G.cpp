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
int main(){
	fast;
	//indef();
	int n,m,ans=0;
	cin >> n >> m;
	vector<int> a(n),b(n+1,1e9);
	for(int i=0;i<n;i++) cin >> a[i];
	while(m--){
		int l,r;
		cin >> l >> r;
		swap(a[l-1],a[r-1]);
	}
	//for(auto &x : a) cout << x << ' ';
	//cout << nl;
	b[0]=-1e9;
	for(int x : a){
		int j=lower_bound(all(b),x) - b.begin();
		b[j]=x;
		ans=max(ans,j);
	}
	cout << ans;
}