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


const int M = 1e9+7;
const int N = 1e4+5;
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

string s;
ll dp[N][20][20][10][2];
ll calc(int pos, int num, int last_digit, bool bound, bool leading) {
    if (pos == s.size()) {
        return (num == 0 && leading) ? 1 : 0;
    }

    ll &ans = dp[pos][num][last_digit][bound];
    if (ans != -1) return ans;
    
    ans = 0;
    int limit = bound ? s[pos] - '0' : 9;

    for (int digit = 0; digit <= limit; ++digit) {
        if (leading && (last_digit + digit) % 3 == 0) continue;
        bool new_bound = bound && (digit == limit);
        ans += calc(pos + 1, (num * 10 + digit) % 19, digit, new_bound, leading || digit > 0);
        ans %= M;
    }

    return ans;
}
void reset(int n) {
	for(int i = 0; i <= n; i++) 
		for(int j = 0; j <= 19; j++) 
			for(int k = 0; k <= 19; k++)
				for(int z = 0; z <= 1; z++)
					dp[i][j][k][z] = -1;
}
ll compute_range(string num) {
    s = num;
    reset(num.size() - 1);
    return calc(0, 0, 0, 1, 0);
}
bool check_edge(string s) {
	int num = 0;
	for(int i = 0; i < s.size(); i++) {
		num = (num * 10 + (s[i] - '0')) % 19;
		if(i > 0) {
			int l = s[i - 1] - '0';
			int r = s[i] - '0';
			if((l + r) % 3 == 0) return false;
		}
	}
	return num == 0;
}
void solve(int id) {
    string a, b;
    cin >> a >> b;

    ll left = compute_range(a);
    ll right = compute_range(b);

    cout << (right - left + check_edge(a) + M) % M << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}