#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
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
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbg(x) cerr << (x) << ' ';


const int M = 998244353;
const int N = 5e6+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

void indef(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}
ll phi[N];
ll a,b;
void calc(){
	for (int i = 0; i < N; i++)
        phi[i] = i;

    for (int i = 2; i < N; i++) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
// 685448185
ll euler(ll n,ll num){
	ll gcd = __gcd(n,num);
	ll ans = phi[n] * phi[num] / phi[gcd];
	ans = ((ans % M) * (gcd % M)) % M;
	return ans;
}
int main(){
	fast;
	indef();
	// auto start = std::chrono::high_resolution_clock::now();
	calc();
	
	cin >> a >> b;
	ll ans = 0;
	for(ll i=1;i<=b;i++){
		(ans += euler(a,i)) %= M;
		
	}
	// auto stop = std::chrono::high_resolution_clock::now();
	// auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	// cout << duration.count() << nl;
	cout << ans;
}
