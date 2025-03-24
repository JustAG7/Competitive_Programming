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
//tt=1 neu ko co truy van
void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	int l=0,r=0;
	while(l<n && r<m){
		if(a[l]<=b[r]){
			cout << a[l] << ' ';
			l++;
		}
		else{
			cout << b[r] << ' ';
			r++;
		}
		if(l==n && r<m){
			while(r<m){
				cout << b[r] << ' ';
				r++;
			}
			break;
		}
		if(l<n && r==m){
			while(l<n){
				cout << a[l] << ' ';
				l++;
			}
			break;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}