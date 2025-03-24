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

ll getHash(int i,int j,vector<ll> h,vector<ll> POW,ll M) {
    return (h[j] - h[i - 1] * POW[j - i + 1] + M * M) % M;
}
void solve(){
	string s;
	cin >> s;
	s=" " + s;
	int n=s.size(),base=31;
	vector<ll> POW(n+2,0);
	vector<ll> h(n+2,0);
	vector<ll> rh(n+2,0);	
	POW[0]=1;	
	for(int i=1;i<=n;i++){
		POW[i]=(POW[i-1]*base) % M;
		h[i]=(h[i-1]*base+ s[i]-'A'+1)% M;
		rh[i]=(rh[i-1]*base+s[n-i]-'A'+1)%M;
	}
	vector<int> res(n+5,0);
	for(int l=1;l<=n/2+1;l++){
		int ans=0;
		if(h[l]==rh[l]){
			ll tmp=h[l];
			for(int i=1;i<=n-l+1;i++){
				if(tmp == getHash(i,i+l-1,h,POW,M)) ans++;
			}
			res[l]=ans;
		}

	}
	int q;
	cin >> q;
	while(q--){
		int r;
		cin >> r;
		if(res[r]>=3) cout << "YES " << res[r] << nl;
		else cout << "NO" << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}