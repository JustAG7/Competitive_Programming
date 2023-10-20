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
	int n,k;
	cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];  
    for(int i=0;i<n;i++){
    	if(a[i]>=k){
    		cout << 1 << nl;
    		return;
    	}
    }
    int l=0,r=0;
    ll sum=0;
    int ans=INT_MAX;
    while(r<n){
        sum+=a[r];
        while(sum>=k || a[l]<0){
            ans=min(ans,r-l+1);
            sum-=a[l];
            l++;
        }
        r++;
    }
	cout << (ans == INT_MAX ? -1 : ans) << nl;
}
int main(){
	fast;
	indef();
	int tt;
	cin >> tt;
	while(tt--) solve();
}