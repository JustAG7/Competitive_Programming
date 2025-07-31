#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>

const int M = 1e9+7;
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
	int n;
	cin >> n;
	vector<int> a(n + 1,0),res(n + 1,0);
	unordered_map<int,int> mp;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(res[i - 1] + 1 == a[i]) res[i] = res[i - 1] + 2;
		else res[i] = res[i - 1] + 1;
	}
	cout << res[n] << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}