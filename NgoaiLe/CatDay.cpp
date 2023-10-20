#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	auto start = high_resolution_clock::now();
	int n,k,l=1,r=0;
	cin >> n >> k;
	vector<int> a(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		r=max(r,a[i]);
	}
	while(l<=r){
		int mid=(l+r)/2,cnt=0;
		bool check=false;
		for(int i=0;i<n;i++){
			cnt+=a[i]/mid;
			if(cnt>=k){
				check=true;
				break;
			}
		}
		if(check) l=mid+1;
		else r=mid-1;
	}
	cout << l-1;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << " ms" << endl;
	return;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}