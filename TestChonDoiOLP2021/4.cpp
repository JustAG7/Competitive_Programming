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
	string s;
	cin >> s;
	int ans=s.size();
	stack<int> st;
	st.push(0);
	for(int i=1;i<s.size();i++){
		if(!st.empty()){
			if(s[i]=='1'){
				if(s[st.top()]=='1' || s[st.top()]=='0'){
					ans-=2;
					st.pop();
				}
			}
			else st.push(i);
		}
		else st.push(i);
	}
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}