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
	string s1,s2;
	cin >> s1 >> s2;
	char l=s1[s1.size()-1],r=s2[s2.size()-1];
	if(l=='L'){
		if(r!=l)cout << ">" << nl;
		else{ 
			if(s1.size()==s2.size()) cout << "=" << nl;
			else if(s1.size()<s2.size()) cout << "<" << nl;
			else cout << ">" << nl;
		}
	}
	else if(l=='S'){
		if(r!=l)cout << "<" << nl;
		else {
			if(s1.size()==s2.size()) cout << "=" << nl;
			else if(s1.size()<s2.size()) cout << ">" << nl;
			else cout << "<" << nl;
		}
	}
	else{
		if(r=='L') cout << "<" << nl;
		else if(r=='S') cout << ">" << nl;
		else{
			if(s1.size()==s2.size()) cout << "=" << nl;
			else if(s1.size()<s2.size()) cout << "<" << nl;
			else cout << ">" << nl;
		}
	}
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}