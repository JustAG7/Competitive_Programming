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
	cin >> s;
	//32 , 64, 128 -> 32 * 2^n
	int ans=1;
	for(int i=0,n=32;i<s.size();i++){
		if(i>=n){
			ans++;
			n*=2;
		}
	}
	for(int i=0;i<ans;i++){
		cout << "long ";
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}