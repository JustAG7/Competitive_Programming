#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
bool cmp(ii &a, ii &b){
	if(a.X == b.X) return a.Y < b.Y;
	return a.X > b.X;
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<ii> res(n);
	// thu tu tu dien => a[i] < b[i] => sap xep tang dan
	for(int i=0;i<n;i++) {
		cin >> a[i];
		b[i] = a[i];
		res[i] = {a[i], i};
	}
	sort(all(res), cmp);
	vector<pair<pair<int,int>,int>> query;
	int q;
	cin >> q;
	vector<int> ans(q);
	for(int i=0;i<q;i++){
		int k, p;
		cin >> k >> p;
		query.pb({{k, p}, i});
	}
	ordered_set s;
	sort(all(query));
	int it = 0;
	for(int i=0;i<q;i++){
		// cerr << query[i].X.X << ' ' << query[i].X.Y << nl;
		while(it < query[i].X.X){
			s.insert(res[it].Y);
			it++;
		}
		int pos = *s.find_by_order(query[i].X.Y - 1);
		// cerr << pos << nl;
		ans[query[i].Y] = a[pos];
	}
	for(int i=0;i<q;i++) cout << ans[i] << nl;
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}