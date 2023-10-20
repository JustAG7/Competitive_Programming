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
	
}
int main(){
	fast;
	indef();
	int H,W,n,h,w;
	cin >> H >> W >> n >> h >> w;
	map<int,int> mp;
	int a[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin >> a[i][j];
			mp[a[i][j]]++;
		}
	}
	H-=h;
	W-=w;
	for(int i=0;i<=H;i++){
		for(int j=0;j<=W;j++){
			map<int,int> tmp;
			for(int l=i;l<i+h;l++){
				for(int r=j;r<j+w;r++){
					tmp[a[l][r]]++;
				}
			}
			int ans=mp.size();
			for(auto const& [x,y] : mp){
				if(tmp[x]==y){
					ans--;
				}
			} 
			cout << ans << ' ';
		}
		cout << nl;
	}
}