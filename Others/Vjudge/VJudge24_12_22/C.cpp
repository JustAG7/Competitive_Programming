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
const int maxn=2e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

map<int,set<int>> a;
int main(){
	fast;
	indef();
	int n,q;
	cin >> n >> q;
	while(q--){
		int t,x,y;
		cin >> t >> x >> y;
		if(t==1){
			a[x].insert(y);
		}
		else if(t==2){
			a[x].erase(y);
		}
		else{
			auto pos1=a[x].find(y);
			auto pos2=a[y].find(x);
			if(pos1!=a[x].end() && pos2!=a[y].end()) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}