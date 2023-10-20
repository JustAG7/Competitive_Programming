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

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int main() {
	indef();
	fast;
   	int t;
   	cin>>t;
   	while(t--){
  	#define int long long
 	int n,m;
 	cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
	int ans=0;
    int sum=0;
    priority_queue<int,vector<int>,greater<int>>pq;
	for(int i=m;i<n;i++){
	    if(a[i]<0)	pq.push(a[i]);
	    sum+=a[i];
	    while(sum<0){
	        int x=pq.top();
	        pq.pop();
	        x=-1*x;
	        sum+=(2*x);
	        ans++;
	    }
	}
	if(a[m-1]<=0)sum=a[m-1];
	else if(m!=1){ 
		sum=-1*a[m-1];
		ans++;
	}
     
    priority_queue<int> pp;
    for(int i=m-2;i>=1;i--){
        if(a[i]>0)pp.push(a[i]);
        sum+=a[i];
        while(sum>0){
            int x=pp.top();
            pp.pop();
            x=-1*x;
            sum+=(2*x);
            ans++;
        }
    }
    cout << ans << "\n";
   }
}