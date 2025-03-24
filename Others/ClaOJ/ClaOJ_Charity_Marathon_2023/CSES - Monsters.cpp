#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

const int M=1e9+7;
const int N = 1e3+5;

int moveX[] = {1, -1, 0, 0};
int moveY[] = {0, 0, 1, -1};
char moveC[] = {'D','U','R','L'};
void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

int n,m;
queue<pair<int,int>> q;
int d1[N][N],d2[N][N];
int vis[N][N];
char mat[N][N], ans[N*N], par[N][N];
pair<int,int> start,finish;


bool check(int i,int j){
    return 1<=i && i<=n && 1<=j && j<=m;
}
void printAns(int x, int y){
    cout << "YES\n";
    int count = d2[x][y];
    cout << count << nl;
    for(int i = count-1; i >= 0; i--){
        ans[i] = par[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < count; i++)
        cout << ans[i];
    cout << nl;
}
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> mat[i][j];
            if(mat[i][j] == 'M'){
                vis[i][j] = 1;
                q.push({i,j});
            }
            if(mat[i][j] == '#') vis[i][j] = 1;
            if(mat[i][j] == 'A') start = make_pair(i,j);
        }
    }
    //bfs for monsters
    while(!q.empty()){
        auto [u,v] = q.front();q.pop();
        for(int i=0;i<4;i++){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx,dy) && !vis[dx][dy]){
                vis[dx][dy] = 1;
                d1[dx][dy] = d1[u][v] + 1;
                q.push({dx,dy});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!vis[i][j]) d1[i][j] = M;
            vis[i][j] = (mat[i][j] == '#');
        }
    }


    vis[start.first][start.second] = 1;
    q.push({start.first,start.second});
    while(!q.empty()){
        auto [u,v] = q.front();q.pop();
        for(int i=0;i<4;i++){
            int dx = u + moveX[i];
            int dy = v + moveY[i];
            if(check(dx,dy) && !vis[dx][dy] && d2[u][v] + 1 < d1[dx][dy]){
                par[dx][dy] = moveC[i];
                d2[dx][dy] = d2[u][v] + 1;
                vis[dx][dy] = 1;
                q.push({dx,dy});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(mat[i][1]!='#' && mat[i][1]!='M' && vis[i][1]){
            printAns(i,1);
            return;
        }
        else if(mat[i][m]!='#' && mat[i][m]!='M' && vis[i][m]){
            printAns(i,m);
            return;
        }
    }
    for(int i=1;i<=m;i++){
        if(mat[1][i]!='#' && mat[1][i]!='M' && vis[1][i]){
            printAns(1,i);
            return;
        }
        if(mat[n][i]!='#' && mat[n][i]!='M' && vis[n][i]){
            printAns(n,i);
            return;
        }

    }
    cout << "NO";
}
int main(){
    fast;
    indef();
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}