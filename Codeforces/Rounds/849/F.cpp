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

int sumdg(int n){
	int ans=0;
	while(n>0){
		ans+=n%10;
		n/=10;
	}
	return ans;
}
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n,q;
	cin >> n >> q;
	vector<int> a(n);
	set<int> s;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]>9) s.insert(i);
	}
	while(q--){
		int t,l,r;
		cin >> t;
		if(t==2){
			cin >> l;l--;
			cout << a[l] << nl; 
		}
		else{
			cin >> l >> r;
			l--;r--;			
			auto it = s.lower_bound(l);
			while (it != s.end() && *it <= r){
				a[*it] = sumdg(a[*it]);
				if (a[*it] < 10) it = s.erase(it);
				else it++;
			
			}
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}