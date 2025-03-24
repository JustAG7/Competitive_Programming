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
int n;
void process(int n){
	n--;
	if(n==0) {cout << "4";return;}
	if(n==1) {cout << "7";return;}
	process(n/2);
	cout << (n%2 ? "7" : "4");
}
void solve(){
	int n;
	cin >> n;
	process(n);
	cout << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}