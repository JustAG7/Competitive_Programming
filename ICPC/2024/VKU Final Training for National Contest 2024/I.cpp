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

#define DBG(x) cerr << #x << " = " << x << ' ';
#define DBGn(x) cerr << #x << " = " << x << '\n';

const int M = 1e9+7;
const int N = 1e3+5;
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
int page[N];
int table[N][N];
bool selected[N], wanted[N];
void solve(int id){
	int n, m, s, p, q;
	cin >> n >> m >> s >> p >> q;
	for (int i = 1; i <= n; i++) {
		int pg = (i-1) / m + 1;
		int ord = i%m == 0 ? m : i%m;
		table[pg][ord] = i;
		// DBG(i) DBG(pg) DBGn(ord)
	}
	// for(int i = 1, j = 1; i <= m && j <= n; i++) {
	// 	for(int t = 1; t <= m && j <= n; t++, j++) {
	// 		table[i][t] = j;
	// 	}
	// }
	int check_box = 0, button_clicks = 0;
	for(int i = 0; i < p; i++) {
		int x; cin >> x;
		selected[x] = 1;
	} 
	set<int> st;
	for(int i = 0; i < q; i++) {
		int x; cin >> x;
		wanted[x] = 1;
	}
	int maxPage = n / m + (n % m != 0);
	for(int numPage = 1; numPage <= maxPage; numPage++) {
		// int wrong = 0, missed = 0, need = 0;
		int cnt = 0;
		int all_one = 1, all_zero = 1;
		int id = m; 
		if (numPage == maxPage && n%m > 0) id = n%m;
		for(int i = 1; i <= id; i++) {
			int cur = table[numPage][i];
			if (wanted[cur] != 1) all_one += 1; 
			else all_zero += 1;
			cnt += (wanted[cur] != selected[cur]);
		}
		if (cnt > 0) st.insert(numPage);
		check_box += min({all_one, all_zero, cnt});
		// if(need > 0) {
		// 	check_box += min({wrong + missed, need + 1, m - need});
		// 	st.insert(numPage);
		// }
		// else {
		// 	check_box += wrong;
		// 	if(wrong > 0) st.insert(numPage);
		// }
		// dbg(numPage) DBG(all_one) DBG(all_zero) DBGn(check_box)
	}
	// DBG(check_box)
	int ans = check_box;
	int leftPage = st.size() > 0 ? *st.begin() : s;
	int rightPage = st.size() > 0 ? *st.rbegin() : s;
	ans += rightPage - leftPage;
	if(abs(s - rightPage) < abs(s - leftPage)) ans += abs(s - rightPage);
	else ans += abs(s - leftPage);
	cout << ans;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >                           > tt;
	for(int t = 1; t <= tt; t++) solve(t);
}