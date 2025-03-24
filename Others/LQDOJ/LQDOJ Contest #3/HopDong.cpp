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
/* expected output
	1770857
	954786
	1372696
	1438351
	1818028
	1635804
*/
ll calc(ll a,ll b){
	return a + (b / a) + (b % a !=0); 
}

// x : the amount of machines
// n : the amount of products
// we have the formula : 	x + n/x = days (1)
// but we have Cauchy's theorem that  a + b >= 2*sqrt(a*b) when a == b
// so we can get x = n/x <=> x^2 = n => x = sqrt(n)
// calculate days by replacing x in (1) and we have the result

void solve(){
	ll n;
	cin >> n;
	if(n == 1){
		cout << "2\n";
		return;
	}
	cout << calc(sqrt(n),n) << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	while(tt--) solve();
}