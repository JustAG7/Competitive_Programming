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
#define ii pair<int,int>
#define vi vector<int>

const int M=1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	int n,m;
	cin >> n >> m;
	if(m == 1) cout << "0\n";
	else cout << min(n+1,m) << nl;
	for(int i=0;i<n;i++){
		vector<int> a(m);
		iota(all(a),0);
		int pos = max(1,m - i - 1);
		reverse(a.begin(),a.begin() + pos);
		reverse(a.begin() + pos,a.end());
		for(int j=0;j<m;j++) cout << a[j] << ' ';
		cout << nl;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}