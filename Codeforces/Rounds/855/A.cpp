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
void solve(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	transform(all(s),s.begin(),::tolower);
	bool ok =true;
	if(s[0]!='m'){
		cout << "NO\n";
		return;
	}
	int i=0;
	if(s[i]=='m'){
		while(s[i]=='m') i++;
	}
	else ok=false;
	if(s[i]=='e'){
		while(s[i]=='e') i++;
	}
	else ok=false;
	if(s[i]=='o'){
		while(s[i]=='o') i++;
	}
	else ok=false;
	if(s[i]=='w'){
		while(s[i]=='w') i++;
	}
	else ok=false;
	if(ok && i==n) cout << "YES";
	else cout << "NO";
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}
