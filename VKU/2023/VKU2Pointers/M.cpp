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
#define nl '\n'

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van
void solve(){
	int n,m;
	string s1,s2;
	cin >> n >> s1 >> m >> s2;
	if(n==1){
		if(s2==s1) cout << 1;
		else cout << 0;
		return;
	}
	s1+=s1;
	int i=0;
	for(int j=0;j<n;j++){
		if(s1[j]==s2[i]){
			i++;
			for(int l=j+1;l<=j+n;l++){
				if(i==m){
					cout << j+1;
					return;
				}
				if(s1[l]==s2[i]) i++;
			}
		}
		i=0;
	}
	cout << 0;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}