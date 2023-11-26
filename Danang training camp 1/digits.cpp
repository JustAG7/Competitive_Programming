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
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=0;i<(n);i++) {for(int j=0;j<(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "input"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ll p,s,d;
ll countDigit(ll n){
	ll ans = 0;
	while(n > 0){
		ans++;
		n /= 10;
	}
	return ans;
}
ll powNum(ll a,ll b){
	ll ans = 1;
	while(b){
		if (b&1) ans = (ans * a);
		a *= a;
		b /= 2;
	}
	return ans;
}

void solve(){
	cin >> p >> s >> d;
	ll cnt = countDigit(p) - 1;
	// if(p < s) cnt++;
	ll numMod = p % s;
	ll sum = 0;
	ll last = 0;
	ll count = 1;
	bool ok = true;
	while(sum < d){
		ll start = max(p, powNum(10, cnt) + numMod);
		ll end = powNum(10, cnt + 1) - s + numMod;
		// cout << (cnt + 1)*(end/s - (start - 1)/s + 1) << nl; 
		// cout << start << ' ' << end << nl;
		sum += (cnt + 1)*(end/s - (start - 1)/s + 1 );
		if(sum >= d) break;
		last = sum;
		cnt++;
	}
	cnt++;
	ll remain = (d - last)/cnt;
	ll left = (d - last + (p % s == 0))%cnt;
	if((d - last) % cnt == 0) cout << max(p, powNum(10, cnt - 1)) + (remain - 1)*s;
	else{
		ll num = max(p, powNum(10, cnt - 1)) + (remain)*s;
		for(char c : to_string(num)){
			cout << c;
			left--;
			if(left == 0) break;
		}
	}
}
void brute_force(){
	while(true){
		if(countDigit(p) < d){
			d -= countDigit(p);
			p += s;
		}
		else if(countDigit(p) == d){
			cout << p;
			break;
		}
		else{
			for(char c : to_string(p)){
				cout << c;
				d--;
				if(d == 0) break;
			}
			break;
		}
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	solve();
	cout << nl;while(tt--) brute_force();
}