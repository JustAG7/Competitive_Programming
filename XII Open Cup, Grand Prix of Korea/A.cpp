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
const int maxn=105;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

ll x[maxn],c[maxn],vis[maxn];
set<ll>s;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
bool check1(int n){
	for(int i=0;i<n;i++){
		if(!vis[i]) return false;
	}
	return true;
}
bool check2(int n,int t){
	for(int i=0;i<n;i++){
		if(vis[i]!=vis[i%t]) return false;
	}
	return true;
}
int main(){
	fast;
	indef();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i] >> c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[i]!=c[j]){
				ll dis=abs(x[i]-x[j]);
				for(int k=1;k*k<=dis;k++){
					if(dis % k==0){
						s.insert(k);
						s.insert(dis/k);
					}
				}
			}
		}
	}
	for(int i=1;i<=50;i++){
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=n;j++){
			ll dis=(x[j]+i)%i;
			vis[dis]=c[j];
		}
		if(!check1(i)) continue;
		for(int j=1;j<i;j++){
			if(i % j==0 && check2(i,j)){
				s.insert(i);
				break;
			}
		}
	}
	ll ans=0,cnt=0;
    for(auto x:s)  ans+=x,cnt++;
    cout << cnt << ' ' << ans;
}