// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fi first
#define se second
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
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
           
#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )


const int M = 1e9+7;
const int N = 3e5+5;
const ll inf = 1e18;
const ll INF = 0x3f;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};
char moveC[] = {'R', 'L', 'D', 'U'};

void indef(){
	#define JA "WF"
	if(fopen(JA ".inp", "r")){
		freopen(JA ".inp","r",stdin);
		freopen(JA ".out","w",stdout);	
	}
}

ll getNum(string &s) {
	ll ans = 0;
	int dir = isdigit(s[0]) ? 1 : -1;
	int i = isdigit(s[0]) ? 0 : 1;
	for(; i < s.size(); i++) {
		ans = ans * 10 + (s[i] - '0');
	}
	return ans * dir;
}
ll eval(string &s, string &a, string &b) {
	ll x = getNum(a);
	ll y = getNum(b);
	if(s == "SUM") return x + y;
	if(s == "DIF") return x - y;
	if(s == "MAX") return max(x, y);
	if(s == "MIN") return min(x, y);
	return abs(__gcd(x, y));
}

void solve(int id){
	string s;
	cin >> s;
	stack<string> st;
	int i = 0, n = s.size();
	while(i < n) {
		if(isdigit(s[i])) {
			string num = "";
			while(i < n && isdigit(s[i])) {
				num += s[i];
				i++;
			}
			st.push(num);
		}
		else if(isupper(s[i])) {
			string func = "";
			while(i < n && isupper(s[i])) {
				func += s[i];
				i++;
			}
			st.push(func);
			if(i < n && s[i] == '(') i++; 
		}
		else if(s[i] == ')') {
			string b = st.top(); st.pop();
			string a = st.top(); st.pop();
			string func = st.top(); st.pop();
			ll res = eval(func, a, b);
			// cout << func << ' ' << a << ' ' << b << ": " << res << nl;
			st.push(to_string(res));
			i++;
		}
		else if(s[i] == ',' || s[i] == '(') {
			i++;
		}
	}
	cout << st.top();
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	time__("solve") {
		for(int t = 1; t <= tt; t++) solve(t);
	}
}
