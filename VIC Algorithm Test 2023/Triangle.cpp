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
#define ii pair<int,int>
#define vi vector<int>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';


const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int a,b,c;
	cin >> a >> b >> c;
	if(a + b + c != 180){
		cout << "Error";
		return;
	}
	if(a == b || b == c || a == c){
		cout << (a == 60 ? "Equilateral" : "Isosceles") ;
		return;
	}
	cout << "Scalene";
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}