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


struct chess{
	char ch;
	int x,y;
};
int xx;
int yy;
bool cmp(chess &a,chess &b){
	int distA = abs(a.x - xx) + abs(a.y - yy);
	int distB = abs(b.x - xx) + abs(b.y - yy);
	return distA < distB;
}
bool check(vector<chess> &a){
	if(!a.size()) return false;
	char ch = a[0].ch;
	int x = a[0].x;
	int y = a[0].y;
	if(x == xx || yy == y) return ch == 'Q' || ch == 'R';
	else if(y - x == yy - xx || y + x == yy + xx) return ch == 'Q' || ch == 'B';
	return false;
}
void solve(){
	while(true){
		int n;
		cin >> n;
		if(n == -1) return;
		cin >> xx >> yy;
		vector<chess> left, right, up, down, leftup, leftdown, rightup, rightdown;
		for(int i=0;i<n;i++){
			char ch;int x,y;
			cin >> ch >> x >> y;
			chess c;
			c.ch = ch, c.x = x, c.y = y;
			if(x == xx){
				if(y < yy) down.pb(c);
				else up.pb(c);
			}
			else if(y == yy){
				if(x < xx) left.pb(c);
				else right.pb(c);
			}
			else if(y - x == yy - xx){
				if(x < xx) leftup.pb(c);
				else rightdown.pb(c);
			}
			else if(y + x == yy + xx){
				if(x > xx) rightup.pb(c);
				else leftdown.pb(c);
			}
		}
		sort(all(left),cmp);sort(all(right),cmp);
		sort(all(up),cmp);sort(all(down),cmp);
		sort(all(leftup),cmp);sort(all(leftdown),cmp);
		sort(all(rightup),cmp);sort(all(rightdown),cmp);
		if(check(left) || check(right) || check(down) || check(up)) cout << "YES\n";
		else if (check(leftup) || check(leftdown) || check(rightdown) || check(rightup)) cout << "YES\n";
		else cout << "NO\n";
	}
}
int main(){
	fast;
	indef();
	int tt=1;
	// cin >> tt;
	while(tt--) solve();
}

