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
	vector<string> s(10);
	ll ans = 0;
	int tmp = 0;
	for(int i=0;i<10;i++) cin >> s[i];
	for(int i=0;i<10;i++){
		for(int j=0;j<s[i].size();j++){
			if(s[i][j] == 'X'){
				if(i == 0 || j == 0 || i == 9 || j == 9) ans++;
				else if(i == 1 || j == 1 || i == 8 || j == 8) ans+=2;
				else if(i == 2 || j == 2 || i == 7 || j == 7) ans+=3;
				else if(i == 3 || j == 3 || i == 6 || j == 6) ans+=4;
				else ans+=5;
			}
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}