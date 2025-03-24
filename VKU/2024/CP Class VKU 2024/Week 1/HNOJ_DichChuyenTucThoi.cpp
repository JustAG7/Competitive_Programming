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
#define iii pair<int, pair<int,int>>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define dbgArr(a,index) for(int i=0;i<(index);i++) cerr << a[i] << ' ';
#define dbgMat(a,n,m) for(int i=1;i<=(n);i++) {for(int j=1;j<=(m);j++) cerr << a[i][j] << ' '; cerr << nl;}
#define dbg(x) cerr << (x) << ' ';
#define donetest cout << "done\n";


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

int a[N][N], f[N][N];
bool vis[N][N];
int n, m;
int x, y, z, t;
int Vis[N * N];
vector<int> b;
vector<pair<int,int>> g[N * N];
bool check(int dx, int dy){
    return 1 <= dx && dx <= n && 1 <= dy && dy <= m;
}
int get(int x){
    int l = 0, r = b.size() - 1, ans = 0;
    while(l <= r){
        int m = (l + r)/2;
        if(b[m] >= x){
            ans = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return ans;
}
void bfs01(){
    f[x][y] = 0;
    vis[x][y] = 1;
    deque<pair<int,int>> dq;
    dq.pb({x, y});
    while(!dq.empty()){
        auto [u, v] = dq.front();dq.pop_front();
        int pos = get(a[u][v]);
        if(!Vis[pos]){
            Vis[pos] = 1;
            for(auto &[dx, dy] : g[pos]){
                if(vis[dx][dy]) continue;
                vis[dx][dy] = 1;
                f[dx][dy] = f[u][v] + 1;
                dq.push_front({dx, dy});
                
            }
        }
        if(vis[z][t]) return;
        for(int i=0;i<4;i++){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx, dy) && f[dx][dy] != -1 && !vis[dx][dy]){
                vis[dx][dy] = 1;
                f[dx][dy] = f[u][v] + 1;
                dq.pb({dx, dy});
            }
        }
        if(vis[z][t]) return;
    }
}
void solve(){
    cin >> n >> m;
    cin >> x >> y >> z >> t;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            if(a[i][j] == 0){
                f[i][j] = -1;
                continue;
            }
            b.pb(a[i][j]);
        }
    }
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == 0) continue;
            int pos = get(a[i][j]);
            g[pos].pb({i, j});
        }
    }
    // for(int i=0;i<9;i++){
    //     for(auto &[x, y] : g[i]) cout << x <<  ' ' << y << nl;
    //     cout << nl;
    // }
    bfs01();
    cout << f[z][t];
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
