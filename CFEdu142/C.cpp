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
const int maxn=2e5+5;

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
	vector<int> a(n+1,0);
	vector<int> b(maxn);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[a[i]]=i;
	}
	if(n==1){
		cout << 0 << nl;
		return;
	}
	int l = (n+1)/2,r = (n+2)/2;
	if(b[l]>b[r]){
		cout << n/2 << nl;
	}
	else{
		while(l>1 && r<n && b[l]>b[l-1] && b[r]<b[r+1]){
			r++;
			l--;
		}
		cout << (n-(r-l+1))/2 << nl;
	}
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}