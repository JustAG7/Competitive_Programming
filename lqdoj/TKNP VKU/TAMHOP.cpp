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
	void solve(){
		int n,ans=0,sum=INT_MIN;
		cin >> n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin >> a[i];
		sort(all(a));
		for(int i=0;i<n-2;i++){
			int k=i+2;
			for(int j=i+1;j<n-1;j++){
				while(k<n && (a[i]+a[k]) < a[j]*2) k++;
				if((a[i]+a[k])==a[j]*2 && (a[i]+a[k]) % 2==0){
					ans++;
					sum=max(sum,a[i]+a[j]+a[k]);
				}	
			}
		}
		cout << ans << nl << sum;
	}
	int main(){
		fast;
		indef();
		int tt=1;
		while(tt--) solve();
	}