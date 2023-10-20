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
	int n,k;
	cin >> n >> k;
	
	vector<int> a(n),cnt(n+1,0);
	for(int i=0;i<n;i++){
		cin >> a[i];
		cnt[a[i]]++;
	}
	bool ok;
	if(a[0] == a[n-1]){
		if(cnt[a[0]]>=k) cout << "YES\n";
		else cout << "NO\n";
		return;
	}
	if(cnt[a[0]]<k || cnt[a[n-1]]<k){
		cout << "NO\n";
		return;
	}
	int tmp = 0;
	int pos = 0;
	for(int i=0;i<n;i++){
		if(a[i] == a[0]){
			tmp++;
			pos = i;
		}
		if(tmp == k) break;
	}
	tmp = 0;
	for(int i=pos+1;i<n;i++){
		if(a[i] == a[n-1]){
			tmp++;
		}
	}
	cout << (tmp>=k ? "YES\n" : "NO\n");
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}