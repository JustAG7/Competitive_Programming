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

const int M=1e9+7;
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
	string s;
	int n;
	int ans=-1;
	cin >> n;
	cin >> s;
	for(int i=0;i<n-1;i++){
		if(s[i]=='L'){
			if(s[i+1]=='R'){
				ans=i+1;
				break;
			}
		}
		else{
			if(s[i+1]=='L'){
				ans=0;
				break;
			}
		}
	}
	cout << ans << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}