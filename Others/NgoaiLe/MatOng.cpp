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
	int n,r=0;
	ll ans=0;
	cin >> n;
	vector<int> a(n);
	vector<int> b(1e8+5,1);
	for(int i=0;i<n;i++){
		cin >> a[i];
		r=max(r,a[i]);
	}
	for(int i=2;i*i<=r;i++){
		for(int j=i;j<=r;j+=i){
			b[j]++;
		}
	}
	for(int i=0;i<n;i++){
		ans+=(a[i]*b[a[i]]);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
