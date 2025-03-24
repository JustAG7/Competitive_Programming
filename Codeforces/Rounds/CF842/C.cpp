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
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	vector<int> p(n,-1),q(n,-1);
	set<int> s1,s2;
	for(int i=1;i<=n;i++){
		s1.insert(i);
		s2.insert(i);
	}
	for(int i=0;i<n;i++){
		if(s1.count(a[i])){
			p[i]=a[i];
			s1.erase(a[i]);
		}
		else if(s2.count(a[i])){
			q[i]=a[i];
			s2.erase(a[i]);
		}
		else{
			cout << "NO" << nl;
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(p[i]==-1){
			auto it = s1.upper_bound(q[i]);
			if(it==s1.begin()){
				cout << "NO" << nl;
				return;
			}
			it--;
			p[i]=*it;
			s1.erase(p[i]);
		}
		if(q[i]==-1){
			auto it = s2.upper_bound(p[i]);

			if(it==s2.begin()){
				cout << "NO" << nl;
				return;
			}
			it--;
			q[i]=*it;
			s2.erase(q[i]);
		}
	}
	cout << "YES" << nl;
	for(int i=0;i<n;i++) cout << p[i] << ' ';
		cout << nl;
	for(int i=0;i<n;i++) cout << q[i] << ' ';
		cout << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}