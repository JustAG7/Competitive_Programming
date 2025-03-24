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
const int N = 2e5+5;
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
int pre[N];
string s;
int n, cnt;
void adjust(int pos) {
	for(int i = pos; i >= max(0, pos - 3); i--) {
		string t = "";
		for(int j = i; j < min(i + 4, n); j++) {
			t += s[j];
		}
		if(t == "1100") {
			if(pre[i] == 1) continue;
			pre[i] = 1;
			cnt++;
		}
		else {
			if(pre[i] == 0) continue;
			pre[i] = 0;
			cnt--;
		}
	}
}
void solve(int id){
	cin >> s;
	while(s.size() < 4) s += "#";
	n = s.size();
	cnt = 0;
	for(int i = 0; i <= n; i++) pre[i] = 0;
	for(int i = 0; i < n - 3; i++) {
		string t = "";
		for(int j = i; j < i + 4; j++) {
			t += s[j];
		}
		if(t == "1100") {
			pre[i] = 1;
			cnt++;
		}
	}
	int q;
	cin >> q;
	while(q--) {
		int i; char c;
		cin >> i >> c;
		s[i - 1] = c;
		adjust(i - 1);
		cout << (cnt > 0 ? "YES\n" : "NO\n");
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	cin >> tt;
	for(int t = 1; t <= tt; t++) solve(t);
}