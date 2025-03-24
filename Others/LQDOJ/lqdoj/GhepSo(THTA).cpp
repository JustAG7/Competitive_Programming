#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	string s1,s2;
	cin >> s1;
	cin >> s2;
	int n=s1.size(),m=s2.size(),i=0,j=0;
	while(true){
		if(i<n && j<m){
			if(s1[i]==s2[j]){
				if(s1[i+1]>s2[j+1]){
					cout << s2[j];
					j++;
				}
				else{
					cout << s1[i];
					i++;
				}
			}
			else if(s1[i]<s2[j]){
				cout << s1[i];
				i++;
			}
			else{
				cout << s2[j];
				j++;
			}
		}
		else if(i>=n && j<m){
			cout << s2[j];
			j++;
		}
		else if(i<n && j>=m){
			cout << s1[i];
			i++;
		}
		if(i==n && j==m) break;
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}
