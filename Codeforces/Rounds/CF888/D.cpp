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
	ll n;
	cin >> n;
	vector<ll> a(n-1);
	bool ok = true;
	ll l = -1;
	set<ll> s;
	s.insert(n);
	for(int i=0;i<n-1;i++){
		cin >> a[i];
		s.insert(i+1);
	}
	if(a[0] > n) l = a[0];
	else s.erase(s.find(a[0]));
	for(int i=1;i<n-1;i++){
		int diff = a[i] - a[i-1];
		auto pos = s.find(diff);
		if(pos != s.end()) s.erase(pos);
		else{
			if(l == -1) l = diff;
			else ok = false;
		}
	}
    
	ll sum = 0;
	for(auto val : s) sum += val;
// 	cout << l << ' ' << sum << "\n";
	if(l == -1){
	    ll tmp = n*(n+1)/2;
	    if(tmp - a[n-2] == sum) ok = true;
	    else ok = false;
	}
	else{
	    if(l != sum) ok = false;
	}
	cout << (ok ? "YES\n" : "NO\n");
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}