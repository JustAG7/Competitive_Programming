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
	int n,x;
	cin >> n >> x;
	int l = 1, r = 2e5;
	vector<int> a(n),h(n),pref(n+1),length(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> h[i];
	pref[0] = 0;
	for(int i=0;i<n;i++) pref[i+1] = pref[i] + a[i];
	length[n-1] = 1;
    for(int i = n-2; i >= 0; i--){
        if(h[i]%h[i+1] == 0) length[i] = length[i+1]+1;
        else length[i] = 1;
    }

	while(l<=r){
		int m = (l+r)/2;
		bool ok = false;
		for(int i=0;i< n - m + 1;i++){
			if(length[i] < m) continue;
			ll sum = pref[i+m] - pref[i];
			if(sum <= x){
				ok = true;
				break;
			}
		}
		if(ok) l = m + 1;
		else r = m - 1;
	}
	cout << r << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}