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
	int n,m,d;
	cin >> n >> m >> d;
	vector<int> p(n),a(m);
	for(int i=0;i<n;i++) cin >> p[i];
	for(int i=0;i<m;i++) cin >> a[i];
	int ans=0,tmp=-1;
	for(int i=0;i<m;i++){
		int pos = -1;
		// find the index of the a[i] in p
		for(int j=0;j<n;j++){
			if(a[i]==p[j]){
				pos=j;
				break;
			}
		}
		if(tmp==-1) tmp = pos;
		else{
			if(pos<=tmp) ans+= (tmp-pos+d) / d;
			tmp = pos;
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