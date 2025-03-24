#include<bits/stdc++.h>
using namespace std;
#define int long long
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

signed main(){
	fast;
	indef();
	int n;
	cin >> n;
	map<int,int> mp;
	for(int i=1;i<=n;i++) cin >> mp[i];
	int q,tmp=-1;
	cin >> q; 
	while(q--){
		int t;
		cin >> t;
		if(t==1){
			cin >> tmp;
			mp.clear();
		}
		else if(t==2){
			int x,y;
			cin >> x >> y;
			mp[x]+=y;
		}
		else{
			int x;
			cin >> x;
			if(tmp>-1) cout << mp[x]+tmp << nl;
			else cout << mp[x] << nl;
		}

	}
}