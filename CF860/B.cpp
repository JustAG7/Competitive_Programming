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
const int maxn=5e4+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void NONO(){
	cout << -1 << nl;
}
void solve(){
	int m;
	int n;
	cin >> m;
	vector<vector<int>> a(m);
	map<int,int> mp;
	for(int i=0;i<m;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			int x;
			cin >> x;
			a[i].pb(x);
			mp[x]++;
		}
	}
	vector<int> ans;
	for(int i=0;i<m;i++){
		bool ok = false;
		for(int x : a[i]){
			if(mp[x]==1 && !ok){
				ok=true;
				ans.pb(x);
			} 
			mp[x]--;
		}
		if(!ok) return NONO();
	}
	for(int x : ans) cout << x << ' ';
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}
