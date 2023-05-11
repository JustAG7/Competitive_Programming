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
#define vi vector<int> 
#define vvi vector<vector<int>> 

const int M=1e9+7;
const int maxn=2e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
int a[maxn];

int main(){
	fast;
	indef();
	int l,r;
	cin >> l >> r;
	int cnt=0;
	for(int i=1;i<=maxn;i++){
		for(int j=i;j<=maxn;j+=i){
			a[j]++;
		}
		if(a[i]&1 && l<=i && i<=r) cnt++; 
	}
	cout << cnt << nl;
	cnt = 1;
	for(int i=l;i<=r;i++){
		cout << a[i + cnt - 1] << ' ';
		cnt++;
	}
}
