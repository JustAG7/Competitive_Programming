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
#define maxn 105

const ll M=1e9+7;
void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
//tt=1 neu ko co truy van
int main(){
	fast;
	indef();
	char n;
	vector<int> prime={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	int l=0,r=prime.size()-1;
	int cnt=0;
	while(l<=r){
		if(cnt==5) break;
		int mid=(l+r)/2;
		cout << "? " << prime[mid] << nl;
		cnt++;
		cin >> n;
		if(n=='>') l=mid+1;
		else r=mid-1;
	}
	if(l>24) l=24;
	cout << "! " << prime[l];
} 
