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
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> odd,even;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]&1) odd.pb(i);
		else even.pb(i);
	}
	if(odd.size()){
		vector<int> tmp;
		for(auto x : odd) tmp.pb(a[x]);
		sort(all(tmp));
		for(int i=0;i<tmp.size();i++){
			a[odd[i]] = tmp[i];
		}
	}
	if(even.size()){
		vector<int> tmp;
		for(auto x : even) tmp.pb(a[x]);
		sort(all(tmp));
		for(int i=0;i<tmp.size();i++){
			a[even[i]] = tmp[i];
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}