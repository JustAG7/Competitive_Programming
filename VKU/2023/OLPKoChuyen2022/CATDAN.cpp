#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db long double
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

db dt(db x1,db y1,db x2, db y2){
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main(){
	fast;
	indef();
	int ans=0;
	map<db,int> mp;
	db x1,y1,x2,y2,x3,y3,x4,y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	db a=dt(x1,y1,x2,y2), b=dt(x2,y2,x3,y3),c=dt(x3,y3,x4,y4),d=dt(x4,y4,x1,y1);
	mp[a]++;mp[b]++;mp[c]++;mp[d]++;
	int tt;
	cin >> tt;
	while(tt--){
		map<db,int> mpck;
		db a1,b1,a2,b2,a3,b3,a4,b4;
		cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;
		db m=dt(a1,b1,a2,b2),n=dt(a2,b2,a3,b3),o=dt(a3,b3,a4,b4),k=dt(a4,b4,a1,b1);
		mpck[m]++;mpck[n]++;mpck[o]++;mpck[k]++;
		if(mpck[m]==mp[m] && mpck[n]==mp[n] && mpck[o]==mp[o] && mpck[k]==mp[k]) ans++;
	}
	cout << ans;
}