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
const int maxn=1e5+5;

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
	int ans=0;
	map<int,int> mp;
	int nn=n,mx=1;//store the maximum count of the prime number
	for(int i=2;i*i<=n;i++){
		if(nn % i ==0){
			int cnt=0;
			while (nn % i ==0){
				cnt++;
				nn/=i;
			}
			mp[i]=cnt;
			mx=max(cnt,mx);
		}
	}
	if(nn!=1) mp[nn]++; //store the largest number after divide 
	//multiply all the prime number then add to the result
	for(int i=0;i<=mx;i++){
		int cur=1;
		for(auto x : mp){
			if(x.Y>0){
				mp[x.X]--;
				cur*=x.X;
			}
		}
		ans+=cur;
	}
	cout << ans-1 << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}