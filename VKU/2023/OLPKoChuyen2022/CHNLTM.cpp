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

int main(){
	fast;
	indef();
	int n,m;
	cin >> n >> m;
	map<int,int> mp;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		mp[x]++;
	}
	while(m--){
		int ans=0;
		int l,r;
		cin >> l >> r;
		if(l<=1 && 1<=r) ans+=mp[1];
		for(int i=2;i<=r;i*=2){
			if(l<=i && i<=r) ans+=mp[i];
		}
		for(int i=3;i<=r;i*=3){
			if(l<=i && i<=r) ans+=mp[i];
		}
		for(int i=5;i<=r;i*=5){
			if(l<=i && i<=r) ans+=mp[i];
		}
		cout << ans << nl;
	}
}