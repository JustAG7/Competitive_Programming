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
const int maxn=1005;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

vector<multiset<int>> s(4*maxn);
int t,p,n=0;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
void add(int id,int l,int r,int p){
	s[id].insert(p);
	if(l==r) return;
	int m=(l+r)/2;
	add(id*2,l,m,p);
	add(id*2+1,m+1,r,p);
}
void remove(int id,int l,int r,int p){
	s[id].erase(p);
	if(l==r) return;
	int m=(l+r)/2;
	remove(id*2,l,m,p);
	remove(id*2+1,m+1,r,p);
}
int get(int id,int l,int r){
	if(l==r) {cout << *s[id].begin() << ' ';return *s[id].begin();}
	int m=(l+r)/2;
	return __gcd(get(id*2,l,m),get(id*2+1,m+1,r));
}
void solve(){
	cin >> t >> p;
	if(t==1) {n++;add(1,1,n,p);}
	else {remove(1,1,n,p);}
	cout << get(1,1,n) << nl;
}
int main(){
	fast;	
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}