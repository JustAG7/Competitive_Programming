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
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int find(int i,int x,vector<pair<int,int>> a){	
	if(a[x].X==i) return a[x].Y;
	else return a[x].X;
}
int main(){
	fast;
	indef();
	int n,m,ans=0;	
	cin >> n >> m;
	vector<pair<int,int>> a(m+5);
	vector<set<int>> b(n+5);
	for(int i=1;i<=m;i++){
		int x,y;
		cin >> x >> y;
		a[i].X=x;
		a[i].Y=y;
		b[x].insert(y);
		b[y].insert(x);
	}
	for(int i=1;i<=n;i++){
		if(b[i].size()>0){
			ans++;
			if(b[i].size()==1){
				auto tmp=b[i].begin();
				b[a[*tmp].X].erase(*tmp);
				b[a[*tmp].Y].erase(*tmp);
			}
			else{
				int tmp=0;
				int k=0;
				for(auto x : b[i]){
					int tmpx=find(i,x,a);
					if(b[tmpx].size()>tmp){
						k=x;
						tmp=b[tmpx].size();
					}
				}
				b[a[k].X].erase(k);
				b[a[k].Y].erase(k);
			}
		}
	}
	cout << ans;
}