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
	int n;
	cin >> n;
	vector<int> a(n),b(n),c(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];
	c[0]=1;
	vector<pair<int,int>> p;
	for(int i=1;i<n;i++){
		p.pb({a[i]*b[i],i});
	}
	sort(all(p));
	int tmp=n;
	for(int i=0;i<p.size();i++){
		c[p[i].Y]=tmp;
		tmp--;
	}
	for(int i=1;i<n;i++){
		if(a[i]*b[i]*c[i]<a[0]*b[0]*c[0]){
			cout << "impossible";
			return;
		}
	}
	for(int i=0;i<n;i++) cout << c[i] << ' ';

}
int main(){
	fast;
	indef();
	int tt=1;
	///cin >> tt;
	while(tt--) solve();
}