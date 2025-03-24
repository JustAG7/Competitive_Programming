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
void NONO(){
	cout << "No\n";
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int cnt=0;
	for(int i=0;i<n;i++) cin >> a[i];
	sort(all(a));
	if(n==1) return NONO();
	int tmp = a[n-1]-a[0];
	for(int i=0,r=n-1;i<cnt;i++,r-=2){
		swap(a[i],a[r]);
	}
	cout << "Yes\n";
	for(int i=0;i<n;i++) cout << a[i] << ' ';
		cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}
