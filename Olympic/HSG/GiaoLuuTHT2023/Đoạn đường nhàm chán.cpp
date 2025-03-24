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


int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	map<int,int> mp;
	int n,k,ans=0,cnt=0;
	cin >> n >> k;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0,j=-1;i<n;i++){
		while(j+1<n){
			if(cnt>=k && mp[a[j+1]]==0) break;
			j++;
			mp[a[j]]++;
			if(mp[a[j]]==1) cnt++;
		}
		ans+=j-i+1;
		mp[a[i]]--;
		if(mp[a[i]]==0) cnt--;
	}
	cout << ans;
}