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

const int M = 2e9+7;
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
int f[105][105];
int d[105][105][105];
bool vis[105][105];
int n, m;
ii ban[1005], ball[105];

void bfs(int x, int y, int cur) {
    queue<ii> q;
    for(int i=0;i<=101;i++){
        for(int j=0;j<=101;j++){
            vis[i][j] = false;
            d[cur][i][j] = M;
        }
    }
    vis[x][y] = true;
    d[cur][x][y] = 0;
    q.push({x, y});
    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if (0 <= dx && dx <= 101 && 0 <= dy && dy <= 101 && f[dx][dy] != -1 && !vis[dx][dy]) {
                d[cur][dx][dy] = d[cur][u][v] + 1;
                vis[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }   

    for(int i=0;i<=101;i++){
        for(int j=0;j<=101;j++){
            if(f[i][j] != -1) f[i][j] = max(f[i][j], d[cur][i][j]);
        }
    }
}

void sub1() {
    for (int i = 1; i <= n; i++) {
        f[ban[i].X][ban[i].Y] = -1;
    }


    for (int i = 1; i <= m; i++) {
        bfs(ball[i].X, ball[i].Y, i);
    }

    
    int ans = M;
    for (int i = 0; i <= 101; i++) {
        for (int j = 0; j <= 101; j++) {
            if (f[i][j] != -1) {
                if (ans > f[i][j]) {
                    ans = f[i][j]; 
                }
            }
        }
    }

    if (ans == M) {
        cout << -1;
        return;
    }

    ll sum = inf;
    for(int i=0;i<=101;i++){
        for(int j=0;j<=101;j++){
            if(f[i][j] != -1){
                ll res = 0;
                for(int k=1;k<=m;k++){
                    res += d[k][i][j];
                }
                sum = min(sum, res);
            }
        }
    }
    cout << sum;
}


void sub2(){
	vector<int> dx, dy;
	for(int i=1;i<=m;i++){
		dx.pb(ball[i].X);
		dy.pb(ball[i].Y);
	}
	sort(all(dx)); sort(all(dy));
	ll x = dx[m / 2], y = dy[m / 2];
	ll sum = 0;
	for(int i=1;i<=m;i++){
		sum += abs(ball[i].X - x) + abs(ball[i].Y - y);  
	}
	cout << sum;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        int x, y; cin >> x >> y;
        ban[i] = {x, y};
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        ball[i] = {x, y};
    }
    if(n > 0) sub1();
    else sub2();
}

int main(){
    fast;
    indef();
    int tt = 1;
    // cin >> tt;
    while(tt--) solve();
}
