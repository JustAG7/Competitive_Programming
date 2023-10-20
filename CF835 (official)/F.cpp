#include<bits/stdc++.h>
using namespace std;
#define int long long
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
	int n,c,d;
	cin >> n >> c >> d;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	sort(rall(a));
	int l=0,r=1e16+2;
	while(l<r){
		int m = l + (r-l+1)/2;
		int sum = 0;
		for(int i=0;i<d;i++){
			if(i % m <n) sum+=a[i % m]; //could be out of the array
		}
		if(sum>=c) l=m;
		else r=m-1;
	}
	if(l==0) cout << "Impossible";
	else if (l==1e16+2) cout << "Infinity";
	else cout << l-1;
	cout << nl;
}
signed main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}