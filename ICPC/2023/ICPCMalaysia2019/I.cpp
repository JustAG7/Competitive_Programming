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
const int maxn=300;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void solve(){
	vector<pair<int,char>> a;
	for(int i=0;i<3;i++){
		string s;
		cin >> s;
		for(int i=1;i<s.size();i++){
			if(s[i]!='.'){
				a.pb({i,s[i]});
			}
		}
	}
	sort(all(a));
	if(a.size()>0) cout << a[0].Y;
	else cout << "You shall pass!!!";
}
int main(){
	fast;
	indef();
	int tt=1;
	while(tt--) solve();
}