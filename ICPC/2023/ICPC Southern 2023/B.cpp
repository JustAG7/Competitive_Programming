#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define rep(i,start,n) for(int (i)=(start);(i)<(n);(i)++)
#define rev(i,start,n) for(int (i)=(start);(i)>=(n);(i)--) // Fix the loop condition here
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';

const int M = 1e9+7;
const int N = 1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> res;

	for(int i = 9; i >= 2; --i){
		while(n % i == 0){
			res.push_back(i);
			n /= i;
		}
	}
	if(res.size() > k || n > 9){
		cout << -1 << '\n';
	}
	else {
		while(res.size() < k) res.push_back(1);
		sort(res.begin(), res.end());
		for(int re1 : res) cout << re1;
	}
}

int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}
