#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
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
	int n,m;
	cin >> n >> m;
	vector<int> a(n),b(m);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	int XOR = a[0];
	for(int i=1;i<n;i++) XOR ^= a[i];

	int ans1 = XOR, ans2 = XOR;
	int OR = b[0];
	for(int i=1;i<m;i++) OR |= b[i];
	for(int i=0;i<n;i++) a[i] |= OR;
	int newXOR = a[0];
	for(int i=1;i<n;i++) newXOR ^= a[i];
	cout << min(XOR,newXOR) << ' ' << max(XOR,newXOR) << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}