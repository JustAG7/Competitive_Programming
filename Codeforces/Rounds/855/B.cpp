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
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<pair<int,int>> a(26,{0,0});
	for(int i=0;i<n;i++){
		if(islower(s[i])){
			int lt = s[i]-'a';
			a[lt].X++;
		}
		else{
			int lt = tolower(s[i])-'a';
			a[lt].Y++;
		}
	}
	sort(rall(a));
	int ans=0;
	for(int i=0;i<26;i++){
		int x=min(a[i].X,a[i].Y),y=max(a[i].X,a[i].Y);
		if(x==y) ans+=x;
		else{
			if(k==0){
				ans+=x;
			}
			else{
				while(y-x>1 && k>0){
					y--;
					x++;
					k--;
				}
				ans+=min(x,y);
			}
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
