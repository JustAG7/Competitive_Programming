#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int maxn=300;
const db pi = 3.141592653;
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
	db v;
	cin >> n >> v;
	v/=pi;
	int ans=-1;
	int tmp = 2e6;
	// Volume = pi * h * r^2 (yeah i forgot it lmao)
	for(int i=0;i<n;i++){
		int h,r;
		cin >> h >> r;
		int V = h*r*r;
		if(V>=v){
			if(V<=tmp){
				ans = i+1;
				tmp=V;
			}
		}
	}
	if(ans==-1) cout << "impossible";
	else cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	//cin >> tt;
	while(tt--) solve();
}