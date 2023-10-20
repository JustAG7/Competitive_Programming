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
	int n;
	cin >> n;
	vector<ll> a(n),b(n);
	ll t1=0,t2=0,t3=0;
	for(int i=0;i<n;i++){
		ll x;
		cin >> x;
		a[i]=x;
		b[i]=x*x;
	}
	sort(all(a));
	sort(all(b));
	for(int i=0;i<n-2;i++){
		int k=i+2,r=i+2,tmp=i+2;
		for(int j=i+1;j<n-1;j++){
			while(k<n && a[i]+a[j]>a[k]) k++;
			if(r<=j) r=j+1;
			while(b[i]+b[j]>b[r] && r<k) r++;
			t1+=r-j-1;
			tmp=r;
			while(b[i]+b[j]==b[r]){
				t2++;
				r++;
			}
			t3+=k-r;
			r=tmp;		
		}
	}
	cout << t1 << " " << t2 << " " << t3;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}