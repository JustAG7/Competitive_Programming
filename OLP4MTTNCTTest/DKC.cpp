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
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=1e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[maxn],mp[maxn];
int main(){
	fast;
	indef();
	int n;
	cin >> n;
	int  rp = 0;
	for(int i=0;i<n;i++){
		cin >> a[i];
		mp[a[i]]++;
		if(mp[a[i]]==2) rp++;
	}
	if(rp==0){
		cout << 0;
		return 0;
	}
	int l=0,r=0,ans=INT_MAX;
	bool ok = true;
	while(r<n){
		if(ok){
			mp[a[r]]--;
			if(mp[a[r]]==1) rp--;
		}
		if(rp==0){
			ans=min(ans,r-l+1);
			mp[a[l]]++;
			if(mp[a[l]]==2) rp++;
			l++;
			ok=false;
		}
		else{
			r++;
			ok=true;		
		}

	}
	cout << ans;
}
