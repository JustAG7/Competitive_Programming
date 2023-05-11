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

void solve(){
	int n;
	cin >> n;	
	vector<int> a(n+2,M);
	a[0]=INT_MAX;a[n+1]=INT_MAX;
	for(int i=1;i<=n;i++) cin >> a[i];
	if(n==1){
		cout << "YES" << nl;
		return;
	}
	int valley=0,l=0,r;
	for(int i=1;i<=n;i++){
		if(a[l]>a[i]){
			r=i+1;
		}
		else l=i;
		if(a[l]>a[i] && a[i]<a[r]){
			valley++;
			l=r;
		}
	}
	if(valley==1) cout << "YES";
	else cout << "NO";
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}