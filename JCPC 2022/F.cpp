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

void indef1(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void indef(){
		freopen("sieve.in","r",stdin);

}

void solve(){
	string a,b;
	cin >> a >> b;
	int tmp=0;
	if(a.size()<b.size()) swap(a,b);
	for(int i=0;i<a.size() && i<b.size();i++){
		if(a[i]==b[i]) tmp++;
		else{
			if(i+1<=b.size()) tmp=1;
			break;
		}
	}
	cout << tmp << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}