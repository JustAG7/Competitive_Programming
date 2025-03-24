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
vector<int> t(4*maxn);
vector<int> a(maxn);
void build(int id,int l,int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int m = (l+r)/2;
	build(id*2,l,m);
	build(id*2+1,m+1,r);
	t[id]=t[id*2]+t[id*2+1];
}
int main(){
	fast;
	indef();
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];

}
