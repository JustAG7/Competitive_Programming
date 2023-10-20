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
//*******************************
//*                             *
//*                             *
//*   tt=1 neu ko co truy van   *
//*                             *
//*                             *
//*******************************
void solve(){
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	s=s+"#";
	int a=0,b=0,cnt=1;
	vector<int> rs;
	if(s[0]=='B') rs.pb(0);
	for(int i=1;i<n;i++){
		if(s[i]==s[i-1]) cnt++;
		else{
			rs.pb(cnt);
			cnt=1;
		}
	}
	rs.pb(cnt);
	for(auto &x : rs) cout << x << ' ';
	int i=0,j=rs.size()-1,qt=0;
	while(i<=j){
		if(a==k){
			cout << "NO";
			return;
		}
		if(b==k){
			cout << "YES";
			return;
		}
		if(s[i]=='W'){
			qt=(qt+1)%2;
			i++;
		}
		if(s[j]=='W'){
			qt=(qt+1)%2;
			j--;		
		}
		else{
			if(cnt&1) a++;
			else b++;
			if(s[i+1]=='B')i++;
			else j--;
		}
		cnt++;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}