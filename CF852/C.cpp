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
	vector<int> a(n+1),cnt(n+1,0);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cnt[a[i]]=i;
	}
	int l=1,r=n,tmp=1;
	while(l<=r){
		bool ok = true;
		// vi tri a[i]>a[i-1] o ben trai nhung a[i-1] != 1 hoac n
		// vi tri a[i+1]<a[i] o ben phai nhung a[i+1] != 1 hoac n
		// neu ko thoa man dk tiep tuc kiem tra va tang min hoac giam max o 2 dau
		if(cnt[n]==l){
			ok=false;
			l++;n--;
		}
		else if(cnt[n]==r){
			ok=false;
			r--;n--;
		}

		if(cnt[tmp]==l){
			ok=false;
			tmp++;l++;
		}
		else if(cnt[tmp]==r){
			ok=false;
			tmp++,r--;
		}
		if(ok){
			cout << l << ' ' << r << nl;return;
		}
	}
	cout << -1 << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}